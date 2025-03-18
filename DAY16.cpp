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


//Problem:median in a rowwise sorted matrix
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
