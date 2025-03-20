//problem:valid anagram
//https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
       int count1[26]={0}; 
      int count2[26]={0};
      for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        count1[index]++;
      }
       for(int i=0;i<t.length();i++){
        int index=t[i]-'a';
        count2[index]++;
      }
      for(int i=0;i<26;i++){
        if(count1[i]!=count2[i]){return false;}
      }
      return true;
    }
};
//approach: counted the occurance of each alphabet in both of the string and for the given strings to be anagram both arrays storing the count should be equal
//tc:O(N+M),where n and m are the length of both the strings
//SC:O(1)

//problem:longest common prefix
//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     string ans="";
     if (strs.size()==1){
        return strs[0];
     }
     for(int i=0;i<strs.size()-1;i++){
        string temp="";
        int j=0;
        while(strs[i][j]==strs[i+1][j] && j<min(strs[i].length(),strs[i+1].length())){
            temp.push_back(strs[i][j]);
            j++;
        }if(temp.length()==0){
            return "";
        }
        else if (ans.length()>0 && temp.length()>0 && ans.length()<temp.length()){
            continue;
        }
       else{ ans=temp;}
     }
     return ans; 
    }
};
//approach :stored the common prefix of two strings at a time and then updated it accordingly and returned the ans
//TC:O(N),where N is the the size of given vector
//SC:O(N),where N is the size of answer string
