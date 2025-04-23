//Problem:Palindromic partitioning
//https://leetcode.com/problems/palindrome-partitioning/description/
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    void solve(string s, int index, vector<string>& temp, vector<vector<string>>& ans) {
        if (index == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int len = 1; index + len <= s.length(); ++len) {
            string str = s.substr(index, len);
            if (isPalindrome(str)) {
                temp.push_back(str);
                solve(s, index + len, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        solve(s, 0, temp, ans);
        return ans;
    }
};
//approach:incremented the substring length and if got the valid palindromic substring then pushed it to ans
//TC:O(n*(2^n))
//SC:O(N*2^n))
