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

//Problem3: Next Permutation
//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){ 
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};
//Approach:found the first decreasing element from the right of the list Then,found the smallest element from the right side that is greater than the first decreasing element
//then swapped these two elements and lastly reversed the list from the first decreasing element to the end of the list.
//TC:O(N)
//SC:O(1)
