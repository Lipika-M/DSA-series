//problem:Repeated string match
//https://leetcode.com/problems/repeated-string-match/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string s = a;
        
         while (s.length() < b.length()) {
            s += a;
            count++;
        }
        if (s.find(b) != string::npos) {
            return count;
        }
        s+=a;count++;
        if (s.find(b) != string::npos) {
            return count;
        }
        return -1;
    } };
//approach:we keep adding till we find b or if not found then returned -1
//TC:O(N+M)
//SC:O(1)
 ************IMPORTANT***************
//problem:Shortest palindrome
//https://leetcode.com/problems/shortest-palindrome/

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;  // Handle empty string case

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        string temp = s + "#" + rev_s;  // Use '#' as a delimiter to avoid overlap
        int n = temp.length();
        
        vector<int> lps(n, 0);  // KMP LPS array

        // Compute KMP failure function (LPS)
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }

         int palin_length = lps[n - 1];  
        string suffix = s.substr(palin_length);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};
//approach:used KMP algorithm to correctly find the prefix and generating the desired output palindromic string
//TC:O(N)
//SC:O(1)
