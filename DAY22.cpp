//problem:minimum add to make parenthesis valid
//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
    int minAddToMakeValid(string s) {
         stack<char>temp;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                temp.push(ch);
            }
             else{
                if(!temp.empty() && temp.top()=='('){
                    temp.pop();
                }
                else 
                temp.push(ch);
             }}
    return temp.size();}
};
//approach: we used a stack to eliminate the valid part and then the remaining stack size would give number of elements to be inserted to make it a valid parentheis
//TC:O(N)
//SC:O(M)(where m is the moves required)
