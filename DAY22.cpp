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

//problem:sum of beauty of all substring
//https://leetcode.com/problems/sum-of-beauty-of-all-substrings/submissions/1586298044/
class Solution {
public:
    int ans = 0;
    int beautySum(string s) {

        for (int i = 0; i < s.length(); i++) {
            map<char, int> mp;
            for (int j = i; j < s.length(); j++) {
                // counting the frequency of each character
                mp[s[j]]++;

                int leastFrequent = INT_MAX;
                int mostFrequent = INT_MIN;
                // Finding most frequent and least frequent chracter
                for (auto it : mp) {
                    leastFrequent = min(leastFrequent, it.second);
                    mostFrequent = max(mostFrequent, it.second);
                }
                ans += mostFrequent - leastFrequent;
            }
        }

        return ans;
    }
};
//approach: found all the substring and then added their beauty
//TC:O(N^2)
//SC:O(1)
