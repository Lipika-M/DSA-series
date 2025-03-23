//problem:longest palindrome substring
//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
    private:
       bool ispalindrome(string p){
        int i=0;
        int j=p.length()-1;
        while(i<=j){
            if(p[i]!=p[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
       }
public:
    string longestPalindrome(string s) {
        int length =0;
        string ans="";
        if(ispalindrome(s)){return s;}
         
        
        for(int i=0;i<s.length();i++){
            char f=s[i];
            int position=s.find(f,i+1);
            if(position<s.length()){
               
               int l=position-i+1;
                string temp=s.substr(i,l);
                if(ispalindrome(temp)){
                
                 length=max(length,l); 
                  
                if(l>=length){
                ans=temp;
                  }
                    }
                while(l<s.length() && position<s.length()){
                
                    position=s.find(f,position+1);
                     
                        l=position-i+1;
                        temp=s.substr(i,l);
                        if(ispalindrome(temp)){
                            length=max(length,l);
                            if(l>=length){
                                ans=temp;
                            }
                        }   }}}
        if (ans==""){
            ans=s.substr(0,1);
             
        }
        return ans;
    }
};
//approach:created substrings that are palindrome and then compared their length to find the maximum 
//TC:O(N*N)
//SC:O(M)(where m is the length of the longest substring which is palindromic)
