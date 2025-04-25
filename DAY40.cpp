//PROBLEM:word break
//https://leetcode.com/problems/word-break/description/
class Solution {
    unordered_map<int, bool> memo;

    bool solve(const string& s, int index, const unordered_set<string>& dict) {
        if (index == s.length()) return true;
        if (memo.count(index)) return memo[index];   

        for (int len = 1; index + len <= s.length(); ++len) {
            string str = s.substr(index, len);
            if (dict.count(str) && solve(s, index + len, dict)) {
                return memo[index] = true;
            }
        }

        return memo[index] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(s, 0, dict);
    }
};
//approach:used recursion ,backtracking and memoization
//TC:O(n*k)
//SC:O(m)


//problem:N queen
//https://leetcode.com/problems/n-queens/description/
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {

        int x = row;
        int y = col;

        while (y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
        }
        x = row;
        y = col;

        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
            x--;
        }
         x = row;
         y = col;

        while (x < n && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
            x++;
        }
             return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& board,
               int n) {

        if (col == n) {
            ans.push_back(board);
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                // place queen if safe
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        solve(0, ans, board, n);
        return ans;
    }
};
//approach:used recursion &backtracking  
//TC:O(n!*n)
//SC:O(n*n)
