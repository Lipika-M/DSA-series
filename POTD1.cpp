//https://leetcode.com/problems/partition-array-according-to-given-pivot/description/
//https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1
//Partition Array According to Given Pivot
 class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      int n=nums.size();
        vector<int> ans(n, 0);
        int left = 0, right = n - 1;
        
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (nums[i] < pivot) {
                ans[left] = nums[i];
                left++;
            }
            
            if (nums[j] > pivot) {
                ans[right] = nums[j];
                right--;
            }
        }
        
        while (left <= right) {
            ans[left] = pivot;
            left++;
        }
        
        return ans;
    }
};
// Approach: created an answer vector of size equal to the given nums then used two pointers to iterate through each element and compare from pivot and the pushing them to ans vector accordingly
//TC:O(N)
//SC:O(N)
