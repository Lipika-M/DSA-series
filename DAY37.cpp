//Problem:combination sum3
//https://leetcode.com/problems/combination-sum-iii/description/
class Solution {
public:
    void solve(int k, int n, int index, vector<vector<int>>& ans, vector<int>& temp) {
        if (k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (i > n) break;
            temp.push_back(i);
            solve(k - 1, n - i, i+ 1, ans, temp); //used i+1 instead of index +1 because for each recursive call we want to increament the number 
            temp.pop_back();                      //by 1 but index +1 may skip some numbers or even include the same number again.
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k, n, 1, ans, temp);
        return ans;
    }
};
//Approach:used recursion to make valid combinations
//TC:O(N^k)
//SC:O(K)
