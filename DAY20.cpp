//Problem: string to integer
//https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0;  

        
        while (i < s.size() && s[i] == ' ') i++;
        if (i == s.size()) return 0;

         
        if (s[i] == '-') { sign = -1; i++; }
        else if (s[i] == '+') i++;

        
        while (i < s.size() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            
            if (sign * res > INT_MAX) return INT_MAX;
            if (sign * res < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * res);
    }
};
//approach: used the given algo to convert the given string to integer
//tc:O(N)
//SC:O(1)

//sort characters by frequency
//https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
     
    string frequencySort(string s) {
        int n=s.length();
        string ans="";
        unordered_map<char,int>m;
          
         for(int i=0;i<n;i++){
         m[s[i]]++;
         }
         for (int i=n;i>=0;i--){
            for(auto ch:m){
                int temp=i;
                if (ch.second==i)
                while(temp>=1)
                {ans.push_back(ch.first);
                temp--;}
            } 
            }
          return ans;
    }
};
//Approach:We need to sort the given string in descending order of frequency and max frequency possible would be the string length and minimum frequency would be 1
//so first we stored the frequency of each character separately in a map and then run a for loop for frequency in descending order and found the character whose mapping is equal to frequency and then 
//pushed it to the ans string
//TC:O(N*M)
//SC:O(N)
