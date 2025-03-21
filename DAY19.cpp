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

//problem 2:roman to integer
//https://leetcode.com/problems/roman-to-integer/submissions/1581367528/
class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char,int>m(7);
       m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            char ch2=s[i+1];
            if(m[ch]>=m[ch2]){
                ans+=m[ch];
            }
            else if(m[ch]<m[ch2]){
                int num=m[ch2]-m[ch];
                ans+=num;
                i++;
            }
        }
        return ans;
    }
};
//approach:if the value of ith char is less than the value of (i+1)th char then we subtract them and then add to the answer 
//tc:O(N)
//sc:O(1)
