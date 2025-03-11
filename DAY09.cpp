//Problem1:Two Sum
//https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> ans(2,0);
    for(int i=0;i<nums.size();i++){
        for (int j=i+1;j<nums.size();j++){
            if (nums[i]+nums[j]==target){
                ans[0]=i;
                ans[1]=j;
             }
        }
    }
    return ans;
    }
};
//Approach: created a answer vector and then pushed back the i,j that satisfies the given condition
//TC:O(N)
//SC:O(1)

//Problem2:Sortcolors
//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
     int n=nums.size();
     int count0=0;
      int count1=0;
       int count2=0;
     int index=0;
     for (int i=0;i<n;i++){
        if(nums[i]==0){
            count0++; }
        if(nums[i]==1){
            count1++; }
        if(nums[i]==2){
            count2++;}  }
     for(int i=0;i<count0;i++){
        nums[index++]=0;}
     for(int i=0;i<count1;i++){
        nums[index++]=1;
     }
     for(int i=0;i<count2;i++){
        nums[index++]=2;
     }
    }
};
//Approach: counted the occurances of 0,1 and 2 and then updated the given vector by putting each color in the desired position
//TC:O(N)
//SC:O(1)

//Problem3:Maximum Score from Subarray Minimums
//https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0
class Solution {
  public:
    int pairWithMaxSum(vector<int> &arr) {
       int  n=arr.size();
          int msum=-1;
    for (int i=0;i<n-1;i++){
        int mini=min(arr[i],arr[i+1]);//smallest 
        int mini2=max(arr[i],arr[i+1]);//second smallest
        msum=max(msum,mini+mini2);
        for(int j=i+2;j<n && arr[j]<mini2;j++){
            if(arr[j]<mini){
                mini2=mini;
                mini=arr[j];
            }
            int sum=mini+mini2;
            msum=max(msum,sum);  

        }
    }
    return msum;
    }
};
//Approach:travesed through the given vector and while adding every new element checking if its less than the current min value ,if yes then updated the mini value and mini2 value then returning the maximum score
//TC:O(N)
//SC:O(1)
