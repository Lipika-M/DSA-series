//Problem1 Good or bad string
//https://www.geeksforgeeks.org/problems/good-or-bad-string1417/1
bool isvowel(char ch){
    string v="aeiou";
    for(int i=0;i<5;i++){
        if (ch==v[i])
        {return 1;}
    }
    return 0;
}


class Solution {
  public:
    int isGoodorBad(string S) {
         int v=0,c=0;
        for (int i=0;i<S.length();i++){
            if (isvowel(S[i])){
                c=0;
                v++;
                if(S[i+1]=='?'){
                    while(S[i+1]=='?'){
                        v++;
                        i++;
                    }}
              if(v>5){
       return 0;}  
            }
           else
            {c++;
            v=0;
            if(S[i+1]=='?'){
                    while(S[i+1]=='?'){
                        c++;
                        i++;
                    }
            }
           if(c>3){
       return 0;}  
        }

    }
    return 1;
}};
// Approach: travesed the given string and checked if it is vowel or consonant and then updating the count value and checking the condition for a string to be bad 
//TC:O(N)
//SC:O(1)

//Problem2 :Merge Two 2D Arrays by Summing Values
//https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < s1 && j < s2) {
            if (nums1[i][0] == nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;

            } else if (nums1[i][0] > nums2[j][0]) {
                ans.push_back({nums2[j][0], nums2[j][1]});

                j++;
            } else {
                 ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }}
            while (i < s1) {
                ans.push_back({nums1[i][0], nums1[i][1]});

                i++;
            }
            while (j < s2) {
                ans.push_back({nums2[j][0], nums2[j][1]});

                j++;
            }
        

        return ans;
    }
};
//Approach: created a ans matrix and then two pointers iterating the ids of both the vector and pushing the vector in ascending order in answer matrix
//SC:O(N+M)
//TC:O(N+M)
