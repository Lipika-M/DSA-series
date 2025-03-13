//Problem1:Binary Search
//https://l  eetcode.com/problems/binary-search/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if (nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
};
//Approach:Simple Binary search algo
//TC:O(logN)
//SC:O(1)

//Problem:Find First and Last Position of Element in Sorted Array
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans1=-1;
        vector<int>ans(2,-1);
        while(s<=e){
            if (nums[mid]==target){
                ans1=mid;
                e=mid-1;

            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        ans[0]=ans1;
        s=0;
        e=nums.size()-1;
         mid=s+(e-s)/2;
         int ans2=-1;
        while(s<=e){
            if (nums[mid]==target){
                ans2=mid;
                s=mid+1;

            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        ans[1]=ans2;
        return ans;
     }
};
//Approach:To get the left most occurance just updated the end to mid-1 where mid is the index where the target was first found,To get the right most occcurance just updated the start to mid+1 where mid 
//is the index where the target was found
//TC:O(logN)
//SC:O(1)


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if (nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        } 
         s=0;
         e=nums.size()-1;
         mid=s+(e-s)/2;
         ans=-1;
         while(s<=e){
          if(nums[mid]<target){
            ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans+1; 
    }
};
