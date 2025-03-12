 //https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
//https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
//Problem 1:Check if Number is a Sum of Powers of Three
class Solution {
    public:
     bool checkPowersOfThree(int n) {
        while(n >= 3){
            if(n % 3 == 2) return false;
            n /= 3;
        }
        return n!= 2;
        
    }
};
//Approach: we are basically checking till the number is greater than or equal to 3 and updating the value of n in each iteration now if in any iteration ,if the remainder when n is divided by 3 is 2 then false is returned 
//because any number must be of form n=3⁰+3¹+3²...and should not be of  n=3ⁿ+2 form after updating
//sc:O(1)
//TC:(logN)


//problem2:Longest increasing subsequence
class Solution {
  public:
   int lis(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i(0);i<nums.size();i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }}
;
//Approach:created a temp vector that stores basically a strictly increaing subsequence,if the incoming element is less than the last element of the temp vector
//than we replaced the element of the lower bound(first element that is just greater than or equal to arr[i]) of arr[i] then continued to find the longest subsequence
//sc:O(1)
//TC:(NlogN)
