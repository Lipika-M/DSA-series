//Problem : Rotate array 
//https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       vector<int>temp(nums.size());
       for (int i=0;i<nums.size();i++) {
        temp[(i+k)%nums.size()]=nums[i];
       }
       nums=temp;
    }
};
//Approach: used pointers to rotate the given array
//TC:O(N)
//SC:O(N)

//Problem :Move Zeroes
//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i=0;
       for(int j=0;j<nums.size();j++){
        if (nums[j]!=0){
            swap(nums[j],nums[i]);
            i++;
        } } }
};
//Approach:used two pointers to get desired vectors
//TC:O(N)
//SC:(N)
