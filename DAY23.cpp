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
 
