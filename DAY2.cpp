//Problem1 Good or bad string
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
