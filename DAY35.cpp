//Problem:subsets
//https://leetcode.com/problems/subsets/
class Solution {
    private:
    void solve(vector<int>& nums, vector<int>output,int index, vector<vector<int>> &ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums,output,index+1,ans);
        //include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       int index=0;
       vector<int>output;
       solve(nums,output,index,ans); 
       return ans;
    }
};
//APPROACH: used recursion to find every possible subset
//TC:O(2^n)
//SC:O(n)

//Problem:generate parenthesis
//https://leetcode.com/problems/generate-parentheses/description/
class Solution {
    private:
    void solve(vector<int>& nums, vector<int>output,int index, vector<vector<int>> &ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums,output,index+1,ans);
        //include
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       int index=0;
       vector<int>output;
       solve(nums,output,index,ans); 
       return ans;
    }
};
//APPROACH:used recursion to find every possible pair 
//TC:O(2^n)
//SC:O(n)
