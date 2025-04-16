//Problem:Combination sum
//https://leetcode.com/problems/combination-sum/description/
class Solution {
public:
    void findComb(vector<vector<int>>& ans, vector<int>& temp, vector<int>& arr,
          int target, int idx = 0) {
        if (idx == arr.size()) {
            if (target == 0)
                ans.push_back(temp);
            return;
        }
        if (arr[idx] <= target) {
            temp.push_back(arr[idx]);
            findComb(ans, temp, arr, target - arr[idx], idx); // reuse allowed
            temp.pop_back();
        }
        findComb(ans, temp, arr, target, idx + 1); // skip current
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findComb(ans, temp, arr, target);
        return ans;
    }
};
//Approach:used recursion with backtracking
//TC:O(2^N)
//SC:O(K)

//Problem:Combination sum II
//https://leetcode.com/problems/combination-sum-ii/
class Solution {
private:
    void findCombination(vector<vector<int>>& ans, vector<int>& temp,
        vector<int>& arr, int target, int idx) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;

            temp.push_back(arr[i]);
            findCombination(ans, temp, arr, target - arr[i], i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        findCombination(ans, temp, candidates, target, 0);
        return ans;
    }
};
//Approach:used recursion with backtracking
//TC:O(2^N)
//SC:O(K)
