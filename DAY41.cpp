//Problem:Expression add operators
//https://leetcode.com/problems/expression-add-operators/description/
class Solution {
public:
    void solve(vector<string>& ans, string& path, string& num, int target,
               int pos, long long curr, long long prev) {
        if (pos == num.size()) {
            if (curr == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0')
                break;

            string part = num.substr(pos, i - pos + 1);
            long long n = stoll(part);

            if (pos == 0) {
                path += part;
                solve(ans, path, num, target, i + 1, n, n);
                path.erase(path.size() - part.size());
            } else {
                path += '+' + part;
                solve(ans, path, num, target, i + 1, curr + n, n);
                path.erase(path.size() - part.size() - 1);

                path += '-' + part;
                solve(ans, path, num, target, i + 1, curr - n, -n);
                path.erase(path.size() - part.size() - 1);

                path += '*' + part;
                solve(ans, path, num, target, i + 1, curr - prev + prev * n,
                      prev * n);
                path.erase(path.size() - part.size() - 1);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty())
            return ans;

        string path;
        solve(ans, path, num, target, 0, 0, 0);
        return ans;
    }
};
//approach:used recursion with backtracking
//TC:O(4^N)
//SC:O(N)

//Problem:Soduku Solver
//https://leetcode.com/problems/sudoku-solver/description/
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        for(int j=0; j<9; j++){
            if(board[row][j] == dig){
                return false;
            }
        }

        for(int i=0; i<9; i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        int srow = (row/3)*3;
        int scol = (col/3)*3;

        for(int i=srow; i<=srow+2; i++){
            for(int j=scol; j <= scol+2; j++){
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if(row == 9){
            return true;
        }

        int nextRow = row, nextCol = col + 1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        for(char dig='1'; dig<='9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row] [col] = dig;
                if(helper(board, nextRow, nextCol)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
//approach:used recursion with backtracking
//TC:O(9^N)
//SC:O(N)
