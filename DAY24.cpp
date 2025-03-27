// Problem 01: Push Dominoes
// https://leetcode.com/problems/push-dominoes/description/?envType=problem-list-v2&envId=string
class Solution {
public:
    string pushDominoes(string str) {
       int n = str.size();
      int left = 0;
       int right = 0;
      while (right < n) {
            if (str[right] == '.') {
                right++;
              continue;
            }
              if (str[right] == str[left] ||
                (str[left] == '.' && str[right] == 'L')) {
                int i = left;
                while (i < right) {
                    str[i] = str[right];

                    i++;
                }
            } else if (str[left] == 'R' && str[right] == 'L') {
                int i = left;

                int j = right;

                while (i < j) {
                    str[i] = 'R';
                   str[j] = 'L';
                  i++;
                  j--;
                }
            }
          left = right;
         right++;
        }
          if (str[left] == 'R') {
            int i = left;
            while (i < n) {
                str[i] = 'R';
                   i++;
            }
        }
      return str;
    }
};
//approach:tarversed the dominoes using two pointers and the made the changes simultaneously to the string
//TC:O(N)
//SC:O(1)
