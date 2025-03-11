//Problem1 : Spiral Matrix
//https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int srow=0,erow=row-1,scol=0,ecol=col-1;
        int count=0;
        int total=row*col;
        while (count<total){
            for(int i=scol;i<=ecol;i++){
                ans.push_back(matrix[srow][i]);
                count++;
            }
            srow++;
            for(int i=srow;i<=erow;i++){
                ans.push_back(matrix[i][ecol]);
                count++;
            }
            ecol--;
            for(int i=ecol;i>=scol&& count<total;i--){
                ans.push_back(matrix[erow][i]);
                count++;
            }
            erow--;
            for(int i=erow;i>=srow && count<total;i--){
                ans.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }
        return ans;
    }
};
//approach: started from the first row and first column then pushed back it in the ans vector in the desired order and then updated the row and column,while keeping track if all the elements of matrix are traversed 
//TC:O(N*N)
//SC:O(N*N)

//Problem:Rotate image
//https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=row;
        if(row==1){
            return ;
        }
       vector<int>mat;
      for(int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                 mat.push_back(matrix[i][j]);
            }}
        int index=0;
         for(int i=0;i<row;i++){
            for (int j=0;j<col ;j++){
                int newi=j;
                int newj=row-i-1;
                 
                matrix[newi][newj]=mat[index++];
             }
        }
    }
};
//Approach: Observed the old indeces and new indeces of each element and found the pattern in old and new indeces so updated the matrix accordingly
//TC:O(N*N)
//SC:O(N*N)
