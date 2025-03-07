//problem1:  Distribute Money to Maximum Children
//https://leetcode.com/problems/distribute-money-to-maximum-children/
class Solution {
public:
    int distMoney(int money, int children) {
     
      
    money -= children;
    if (money < 0)
        return -1;
    if (money / 7 == children && money % 7 == 0)
        return children;
    if (money / 7 == children - 1 && money % 7 == 3)
        return children - 2;
    return min(children - 1, money / 7);
}
};
//approach: now firstly we satisfied the condition that each child must get atleast one dollar then distributed the remaining money in a fraction of 7 and checked how many children can get in a total of 8 dollar 
//and then calculated the edge cases separately
//TC:O(1)
//SC:O(1)


//Problem 2:Longest Palindrome
//https://leetcode.com/problems/longest-palindrome/
class Solution {
public:
    int longestPalindrome(string s) {
     int arr[52]={0};
     int slen=s.length();
     for(char ch:s){
        if(ch>='a'&& ch<='z')
        {int index=ch-'a'+26;
        arr[index]++;}
        if(ch>='A'&& ch<='Z')
       { int index=ch-'A';
        arr[index]++;}
     } 
     int pair=0;
     for(int i=0;i<52;i++) {
        if (arr[i]>1){
            int n=arr[i]/2;
            pair=pair+n;
        }
     }
     if ((pair*2)==slen){
        return pair*2;}
    else{ 
    return (pair*2)+1;}
     }};
//Approach: created a array that stores the occurance of each character in the string and then traversed the created array and check the possivle no.of pairs of characters (because in order to create a palindrome 
//we need pair of character ) now if the pair * 2 is equal to string length then returned pair*2 else we can keep any character in between to create largest palindrome
//TC:O(N)
//SC:0(1)
