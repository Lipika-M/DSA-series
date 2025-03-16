//Problem:Square root
//https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int s=0;
        int e=n;
        int mid=s+(e-s)/2;
        int ans;
        while(s<=e){
            int m=mid*mid;
            if(m<=n){
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};
//Approach: used binary search to find the square root
//TC:O(log N)
//SC:O(1)
