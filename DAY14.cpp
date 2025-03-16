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

//Problem2:koko eating bananas
//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
    private:
bool possible(vector<int> piles, long long int h,int mid,int n){
 
        long long int giventime=h;
        long long int tooktime=0 ;
        for(long long int i=0;i<n;i++){
            tooktime += (piles[i] + mid - 1) / mid; //this formula is used to calculate the value of ceil division ceil(x/y) more efficiently
             if (tooktime>giventime )
            return false;
             }
        return true;
     }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     
    int s=1;
    int n=piles.size();
    int e=*max_element(piles.begin(), piles.end());
     int mid=s+(e-s)/2;
     int ans=-1;
    while(s<=e){
         if(possible(piles,h,mid,n)){
           ans=mid;
            e=mid-1;
        }
        else
          {  s=mid+1;}
           mid=s+(e-s)/2;  } 
    return ans;  
    }};
//Approach: used binary search
//TC:O(Nlog (max(piles))
//SC:O(1)
//Problem3: Find the Smallest Divisor Given a Threshold
//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
class Solution {
      private:
bool possible(vector<int> nums, int threshold,int mid,int n){
 int sum=0;
 for(int i=0;i<n;i++){
    sum+=(nums[i]+mid-1)/mid;
 }
    if(sum<=threshold){
        return true;
    }
       return false; 
     }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(), nums.end());
        int n=nums.size();
        int mid=s+(e-s)/2;
     int ans=-1;
      while(s<=e){
         if(possible(nums,threshold,mid,n)){
           ans=mid;
            e=mid-1;
        }
        else
          {  s=mid+1;}
           mid=s+(e-s)/2;  } 
    return ans;  
    }};
//TC:O(Nlog (max(nums))
//SC:O(1)
