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


//problem:Partition labels
//https://leetcode.com/problems/partition-labels/description/?envType=problem-list-v2&envId=string
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;

        // Store the last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]] = i;
        }

        vector<int> res;
        int end = mp[s[0]], start = 0;

        for (int i = 1; i <= s.length(); i++) {
            if(i <= end) {
                if(mp[s[i]] > end) {
                    end = mp[s[i]];
                }
            } else {
                res.push_back(end - start + 1);
                start = i;
                end = mp[s[i]];
            }
        }

        return res;
    }
};
//TC:O(N)
//SC:O(N)
