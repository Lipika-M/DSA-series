//Problem:Search in Rotated Sorted Array
//https://leetcode.com/problems/search-in-rotated-sorted-array/
int pivoti(vector<int>& nums) {
    int s = 0;
    int siz = nums.size();
    int e = siz - 1;
    int mid = s + (e - s) / 2;
    int ans=-1;
    while (s <=e) {
        if (nums[0] <= nums[mid]) {
           ans=mid;
            s= mid + 1;

         } 
        else {
            e=mid-1; }
    mid = s + (e - s) / 2; 
    }
    return ans;
}

int binarysearch(vector<int>& nums, int k, int start, int end) {
    int s = start;
    int e = end;
    int mid = s + (e - s) / 2;
    while (s<=e) {
        if (nums[mid] == k) {
            return mid;
        } else if (nums[mid] > k) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
         mid = s + (e - s) / 2;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==1){ 
            if (nums[0]==target)
            {return 0;}
            return -1;
        }
        int pivot = pivoti(nums);
        //sort(nums.begin(),nums.end());
        if (nums[0] <= target && target <= nums[pivot]) {
            return binarysearch(nums, target, 0, pivot);
        } else {
            return binarysearch(nums, target, pivot+1, nums.size() - 1);
        }   }
};
//Approach: since the given array is rotated we find the pivot element and then find the part where the target element lies and then did binary search in that part
//SC:O(1)
//TC:O(log N)
