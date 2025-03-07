// Problem 1: Can PLace Flowers
//https://leetcode.com/problems/can-place-flowers/?envType=problem-list-v2&envId=greedy
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
  int f=flowerbed.size();
  int flower=0;
  if(f==1 && flowerbed[0]==0)
  return 1;
  if (f>1){
if (flowerbed[0]==0 && flowerbed[1]==0){
    flowerbed[0]=1;
    flower++;
  }
  if(flowerbed[f-1]==0 && flowerbed[f-2]==0 ){
    flowerbed[f-1]=1;
    flower++;
  }
  for(int i=1;i<f-1;i++){
    if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
        flowerbed[i]=1;
        flower++;
    }
  }   }
  if(flower>=n){
    return 1;
  } 
    return 0;
     }
};
//Approach: firstly wejust checked that if for any ith place the adjacent place is empty of not if yes then placed the flower there and placed the flowers till it is equal to given n value ,also we checked the
//edge cases separately
//SC:O(1)
//TC:O(N)
