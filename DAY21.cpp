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


// Substrings with K Distinct
// https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-number-of-substrings
class Solution {
public:
    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }

private:
    int atMostK(string& s, int k) {
        if (k < 0) return 0;
        unordered_map<char, int> freq;
        int left = 0, right = 0, count = 0, distinct = 0;

        while (right < s.length()) {
            if (freq[s[right]] == 0) {
                distinct++;
            }
            freq[s[right]]++;
            right++;

            while (distinct > k) {   
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    distinct--;
                }
                left++;
            }

            count += (right - left);  
        }

        return count;
    }
};
// Approach : We use a sliding window to count substrings with at most k distinct characters, expanding the right and shrinking the left when needed. A frequency array (freq[26]) tracks characters efficiently. To get exactly k distinct characters, we subtract countAtMostK(s, k-1) from countAtMostK(s, k) . 
// Cant directly count the only k distinct character substring sas that will leave some cases when in transition so subtract substrings with atmost k and atmost k-1 distinct characters . 
// right will iterate normally left is 0 and will shift accordignly . 

// TC O(n) {each character vistited twice so technically 2n}
// SC O(1) {fixed size array is used}
