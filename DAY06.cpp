//Problem01:Most Visited Sector in a Circular Track
//https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
#include<algorithm>
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> sectors(n,0);
        int len = rounds.size();
        sectors[rounds[0]-1]++;
        for(int i=1; i <= len-1; ++i)
        {
            int start = rounds[i-1];
            int end = rounds[i];
            
            if(start <= end)
            {for(int j = start; j < end; ++j)
                    sectors[j] ++; }
            else
            {
                for(int j = start; j < n; j++)
                    sectors[j]++;
                for(int j = 0; j < end; j++)
                    sectors[j]++;
            } }
     vector<int> temp;
       int maxi=-1;
      for(int i=0;i<n;i++){
         maxi=max(maxi,sectors[i]);
      }
for(int i=0;i<n;i++){
  if (sectors[i]==maxi){
    temp.push_back(i+1);
  }
        }
      return temp;
    }
};
// Approach: Created a vector that keeps a track of how much times a particular track has been visited .Then found out the max occurance of any sector then checked the sectors which was visited the maximum times
//and pushed them to temp vector 
//TC:O(N)
//SC:O(N

//Problem:Stock span problem
//https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
  vector<int> ans(arr.size());
    ans[0] = 1;  
      for (int i = 1; i < arr.size(); i++) {
        int count = 1;
        int j = i - 1;
        while (j >= 0 && arr[j] <= arr[i]) {
            count += ans[j];  
            j -= ans[j];      
        }
  ans[i] = count;
    }
      return ans;
    }
};
//Approach:In this we first initaialised the span of each stock to be 1 then for any ith stock checked the jth((i-1)th) stock span then if the arr[i]>arr[j] then added the jth stock's span to the current stock 
//span then jumped back by reducing j value to ans[j] because it is the number of stocks whose value less than jth stock whose value is less than the current stock
//TC:O(N)
//SC:O(N)
