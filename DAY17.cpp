//problem:Isomorphic strings
//https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map< char,char>ans;
        int i=0;
        int j=0;
        int n=s.length();
        int m=t.length();
        while(i<n){
            ans[s[i++]]='*';
            }
        i=0;
        while(i<n && j<m){
            if(ans[s[i]]!='*' && ans[s[i]]!=t[j]){
                return 0;
            }
            else{
                ans[s[i]]=t[j];
                i++;
                j++;
            }
        }
        i=0;
        j=0;
        unordered_map< char,char>ans2;
        while(j<m){
            ans2[t[j++]]='*';
            }
        j=0;
         while(i<n && j<m){
            if(ans2[t[j]]!='*' && ans2[t[j]]!=s[i]){
                return 0;
            }
            else{
                ans2[t[j]]=s[i];
                i++;
                j++;
            }
        }
        return 1;
    }
};
//approach : stored the mapping of each character in a string and checked if any mapping violates the given set of rules
//TC:O(N+M)
//SC:O(N+M)
