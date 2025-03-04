//Problem 1:Check if Number is a Sum of Powers of Three
//https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
class Solution {
    public:
     bool checkPowersOfThree(int n) {
        while(n >= 3){
            if(n % 3 == 2) return false;³
            n /= 3;
        }
        return n!= 2;
        
    }
};
//Approach: we are basically checking till the number is greater than or equal to 3 and updating the value of n in each iteration now if in any iteration ,if the remainder when n is divided by 3 is 2 then false is returned 
//because any number must be of form n=3⁰+3¹+3²...and should not be of  n=3ⁿ+2 form after updating
//sc:O(0)
//TC:(logN)
