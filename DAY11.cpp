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
