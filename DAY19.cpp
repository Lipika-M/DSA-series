//problem1:maximum nesting depth of the parenthesis
//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
class Solution {
public:
    int maxDepth(string s) {
       int count=0;
       stack<char>st;
       for(int i=0;i<s.length();i++){
        char ch=s[i];
        if (ch=='('){
        st.push(ch);
        int n=st.size();
         count=max(count,n);
        }
        else if (ch==')'){
        st.pop();
        }}
     return count;  
    }};
//approach: used a stack to store the maximum depth of the parenthesis and if closing bracket is encountered then popped it out of the stack
//tc:O(N)
//sc:O(M),where m is the max depth
