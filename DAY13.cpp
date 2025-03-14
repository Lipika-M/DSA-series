//Problem1:Search in Rotated Sorted Array
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

//Problem2:find minimum in rotated array
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
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
    int findMin(vector<int>& nums) {
        int pivot=pivoti(nums);
        int n=nums.size();
        return nums[(pivot+1)%n];
    }
};
// Approach:found the pivot element and returned the next element to it and to keep the index in range we took modulus of the required index of minimum element
//SC:O(1)
//TC:O(log N)

//Problem3:Ceil the floor
//https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=SUBMISSION
#include<algorithm>
bool present(vector<int> &a, int n, int x){
		for(int i=0;i<n;i++){
			if (a[i]==x){
				return 1;
				break;
			}}
		return 0;}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
pair<int, int>ans;
auto lowptr=lower_bound(a.begin(),a.end(),x);
auto upptr=upper_bound(a.begin(),a.end(),x);
int low=*(lowptr-1);
int up=*(upptr);
if(x<a.front()){
	ans.first=-1;
	ans.second=a[0];
}
else if (x>a.back()){
	ans.first=low;
	ans.second=-1;
}
else if (present(a, n,x))
{ans.first=x;
ans.second=x;}

else 
{ans.first=low;
ans.second=up;}
	return ans;
}
//Approach: Used the upper bound and lower bound concept and checked the conditions according to the problem statement
//SC:O(n)
//TC:O(log N)
