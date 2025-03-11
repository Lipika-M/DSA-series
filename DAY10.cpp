//Problem1:Best Time to Buy and Sell Stock
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit=-1;
      int n=prices.size();
      for (int i=0;i<n;i++){
        for (int j=i+1;j<n && prices[j]>prices[i];j++){
            int temp=prices[j]-prices[i];
            profit=max(profit,temp);
        }
      } 
      if (profit<=0)
      return 0;
      return profit;
    }
};
//Approach:Used pointers to keep track of the max profit and then returned it
//TC:O(N)
//SC:O(1)

//Problem2: Rearrange Array Elements by Sign
//https://leetcode.com/problems/next-permutation/description/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     vector<int> p;
     vector<int> n;
     int s=nums.size();
     for (int i=0;i<s;i++ ){
        if(nums[i]<0){
            n.push_back(nums[i]);
        }
         if(nums[i]>0){
            p.push_back(nums[i]);
        }
     }
     int pind=0;
     int nind=0;
     for (int i=0;i<s;i++){
        if(i%2==0){
            nums[i]=p[pind++];
        }
        else{
            nums[i]=n[nind++];
        }
     } 
     return nums;  
    }
};
//Approach:stored the positive and negative integers separately and then arranged them in correct order in the original vector
//TC:O(N)
//SC:O(N)
