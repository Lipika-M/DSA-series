//problem1:
//https://leetcode.com/problems/ugly-number/description/?envType=problem-list-v2&envId=math
class Solution {
public:
     
bool isUgly(int n) {
if (n<=0){
    return false;
}
        
while (n>0 && n%2==0){
    n=n/2;
}
while (n>0 && n%3==0){
    n=n/3;
}
while (n>0 && n%5==0){
    n=n/5;
}return n==1;
}

};
//approach:repeatedly divided the given number with 2,3 & 5 and updating the number and then returning if n==1 i.e. 2,3 and 5 were the only prime factors 
//SC=O(1)
//TC=O(N)
