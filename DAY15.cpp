//Problem:SEARCH A 2D MATRIX
//https://leetcode.com/problems/search-a-2d-matrix/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row * col - 1;
        int mid = start + (end - start) / 2;
        while (start <= end) {
            int element = matrix[mid / col][mid % col];
            if (element == target) {
                return 1;
            } else if (element < target) {
                start = mid + 1;
            }
            else { 
                end = mid - 1;
            }
        mid = start + (end - start) / 2;
        }
        return 0;
    }
};
//Approach :used binary search to implement search in the matrix
//TC:O(log N)
//SC:O(1)

//Problem2:SEARCH A 2D MATRIX II
//https://leetcode.com/problems/search-a-2d-matrix-ii/description/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowind = 0;
        int colind = col - 1;
         while (colind>=0 && rowind<row) {
            int element = matrix[rowind][colind];
            if (element == target) {
                return 1;
            } else if (element < target) {
             rowind++;
            }
            else { 
            colind--;
            }  }
        return 0; }};
//Approach :used binary search to implement search in the matrix
//TC:O(log N)
//SC:O(1)

//problem:kth element of two arrays
//https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
         vector<int>ans;
         for(int i=0;i<a.size();i++){
             ans.push_back(a[i]);
         }
         for(int i=0;i<b.size();i++){
             ans.push_back(b[i]);
         }
         sort(ans.begin(),ans.end());
         return ans[k-1];
    }
};
//Approach: used sorting to find the kth element
//TC:O(Nlog N)
//SC:O(N+M)(N  and M are the size of two arrays)
