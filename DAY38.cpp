//Problem:Letter Combinations of a phone Number
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
    void solve(string digits, string output, int index, vector<string>& ans,
               string mapping[]) {
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }
        string output = "";
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = 0;
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};
//Approach:used recursion with backtracking
//TC:O(2^N)
//SC:O(K)

//Problem:Subsets II
//https://leetcode.com/problems/subsets-ii/description/
class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int> nums,
               int index = 0) {

        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            solve(ans, temp, nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(ans, temp, nums, 0);
        return ans;
    }
//Approach:used recursion with backtracking
//TC:O(2^N)
//SC:O(K)
