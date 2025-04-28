//Problem:single number
//https://leetcode.com/problems/single-number/description/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
       for(int i=0;i<nums.size();i++){
        ans=ans^nums[i];
       } 
       return ans;
    }
};
//Approach:used bit manupulation
//tc:O(1)
//SC:O(1)


//Problem: Minimum Bit Flips to Convert Number
//https:https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        while (start > 0 || goal > 0) {
             if ((start & 1) != (goal & 1)) {
                count++;
            }
             start >>= 1;
            goal >>= 1;
        }
        return count;
    }
};
//Approach:used bit manupulation
//tc:O(1)
//SC:O(1)
