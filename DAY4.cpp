// problem1: Count distinct numbers
//https://leetcode.com/problems/count-distinct-numbers-on-board/
class Solution {
public:
    int distinctIntegers(int n) {
        if (n==1){ return 1;}
        return n-1;
    }
};
//TC:O(1)
//SC:O(1)
//Approach: for any n value the number before it would give remainder 1 and hence all the numbers before n would be included for a given particular n


//Problem 2: chocolate distribution problem
//https://www.geeksforgeeks.org/problems/longest-string-chain/1
 class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size();
        sort( a.begin(),a.end());
        int i=0;
        int mini=INT_MAX;
        while((i+m)<=n){
            int d=a[i+m-1]-a[i];
            mini=min(mini,d);
            i++;
        }
        return mini;
    }
};
// approach: sorted the given array then traveres the array with a window size of given m and returned the minimum encountered difference among all the iterations
//TC:O(nlogn)
//SC:O(1)


