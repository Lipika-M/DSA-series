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
