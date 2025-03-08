// Problem 1: Can PLace Flowers
//https://leetcode.com/problems/can-place-flowers/?envType=problem-list-v2&envId=greedy
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  int f=flowerbed.size();
  int flower=0;
  if(f==1 && flowerbed[0]==0)
  return 1;
  if (f>1){
if (flowerbed[0]==0 && flowerbed[1]==0){
    flowerbed[0]=1;
    flower++;
  }
  if(flowerbed[f-1]==0 && flowerbed[f-2]==0 ){
    flowerbed[f-1]=1;
    flower++;
  }
  for(int i=1;i<f-1;i++){
    if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
        flowerbed[i]=1;
        flower++;
    }
  }   }
  if(flower>=n){
    return 1;
  } 
    return 0;
     }
};
//Approach: firstly wejust checked that if for any ith place the adjacent place is empty of not if yes then placed the flower there and placed the flowers till it is equal to given n value ,also we checked the
//edge cases separately
//SC:O(1)
//TC:O(N)

//Problem:Minimum positive sum subarray
//https://leetcode.com/problems/minimum-positive-sum-subarray/description/?envType=problem-list-v2&envId=prefix-sum
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
         int n=nums.size();
        int ans=INT_MAX;
        for(int window=l;window<=r;window++){
            
              int minsum=INT_MAX;
               for(int i=0;i<n && i+window<=n;i++){
                  int sum=0;
                for(int j=0;j<window  ;j++){
                    int index=i+j;
                    sum=sum+nums[index];
                }
                if ((sum < minsum) && (sum > 0)) {
                    minsum = sum;
                }
             }
        ans=min(ans,minsum);
           } 
           if (ans<=0 ||ans==INT_MAX)
           return -1;
        return ans;
         }};
//Approach: Checked the sum for each window and the stored the minimum sum possible for any windowsize keeping the constraint that sum is greater than equal to zero if no miminmum sum was found then
//returned -1
//TC:O(N²)
//SC:O(1)


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
