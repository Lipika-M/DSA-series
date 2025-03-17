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
