//Problem1: Flipping an image
//https://leetcode.com/problems/flipping-an-image/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int row=image.size();
        int col=image[0].size();
        for(int i=0;i<row;i++){
            int s=0;int e=col-1;
            while(s<=e){
                swap(image[i][s++],image[i][e--]);
                 
            }
        }
       for(int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                 if(image[i][j]==0){
                    image[i][j]=1;
                 }
                 else{
                    image[i][j]=0;
                 }
            }
        } 
        return image;
    }
};
//Approach: first flipped each element horizontally and the returned its inverse
//TC:O(n*n)
//SC:O(1)

//problem2 Number of equivalent dominoes
//https://leetcode.com/problems/number-of-equivalent-domino-pairs/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto& d : dominoes) {
            sort(d.begin(), d.end());
        }
        sort(dominoes.begin(), dominoes.end());
        int count = 0;
        int c = 1;
        for (int i = 1; i < dominoes.size(); i++) {
            if (dominoes[i] == dominoes[i - 1]) {
                count = count + c;
                c++;
            } else {
                c = 1;
            }
        }
        return count;
    }
};
//approach: first sorted each vector in the matrix then sorted the matrix itself then checking the condition and updating the count value
//TC:O(nlogn)
//SC:O(1)
