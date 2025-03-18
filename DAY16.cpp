//problem:unique character in a string
//https://leetcode.com/problems/first-unique-character-in-a-string/description/
class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char, int> mp;

        for (auto a : s) mp[a]++;
        for (int i = 0; i < s.size(); i++)
        if(mp[s[i]] == 1)
        return i;

        return -1;
    }
}; 
//Approach: stored the occurance of each character and returned the first character that is unique 
//TC:O(N)
//SC:O(U)(U is the number of unique character in the string given)


//Problem:median in a rowwise sorted matrix(important)
//https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
      int row = mat.size();
        int col = row;
          
        vector<int>v;
          for(int i=0;i<row;i++){
              for(int j =0;j<col;j++){
                  v.push_back(mat[i][j]);
              }
          }
          
          sort(v.begin(),v.end());
           
           return v[(row*col)/2]; 
    }
};
//approach: Created a vector that stored all the element and then returned the median
//TC:O(row*col*log(row*col))
//SC:O(row*col)

//problem :rotated array
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
//approach:used indices to rotate the array
//TC:O(N)
//SC:O(N)

//PROBLEM:FIND PEAK ELEMENT II
//https://leetcode.com/problems/find-a-peak-element-ii/
class Solution {
public:

    int maxindex(vector<vector<int>>& mat,int& col){
        int index = -1;
        int maxi = INT_MIN;
        for(int i = 0;i<mat.size();i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = m-1;
        int mid;
        while(s<=e){
            mid = s + (e-s)/2;
            int maxRowIndex = maxindex(mat,mid);
            int left = -1;
            int right = -1;
            if(mid-1 >= 0){
                left = mat[maxRowIndex][mid-1];
            }
            if(mid+1 < m){
                right = mat[maxRowIndex][mid+1];
            }
             
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return {maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid] < left){
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return {-1,-1};
    }
    
};
//Approach: found the peak element row index in a column and then compared it with its adjacent cells
//tc:O(N log M)
//SC:O(1)
