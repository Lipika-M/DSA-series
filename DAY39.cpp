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

//Problem:word search
//https://leetcode.com/problems/word-search/description/
class Solution {
public:
    bool issafe(int x, int y, int m, int n, vector<vector<int>>& visited) {
        return x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == 0;
    }

    bool solve(int index, int x, int y, int m, int n, vector<vector<int>>& visited, string& word, vector<vector<char>>& board) {
        if (index == word.length()) return true;
        if (!issafe(x, y, m, n, visited) || board[x][y] != word[index]) return false;

        visited[x][y] = 1;
        bool found = solve(index + 1, x + 1, y, m, n, visited, word, board) ||
                     solve(index + 1, x - 1, y, m, n, visited, word, board) ||
                     solve(index + 1, x, y + 1, m, n, visited, word, board) ||
                     solve(index + 1, x, y - 1, m, n, visited, word, board);

        visited[x][y] = 0; 
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();         
        int n = board[0].size();     
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(0, i, j, m, n, visited, word, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
//approach:used recursion and backtracking
//TC:O(n*m*4^l)
//SC:O(n*m+l))
