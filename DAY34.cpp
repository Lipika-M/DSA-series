//Problem1:Sort a stack
//https://www.geeksforgeeks.org/problems/sort-a-stack/1
void correctorder(stack<int>& s,int val){
    if(s.empty() || !s.empty() &&s.top()<val){
        s.push(val);
        return;
    }
    int temp=s.top();
    s.pop();
    correctorder(s,val);
    s.push(temp);
}
void SortedStack :: sort()
{
    if(this->s.empty()){return;}
    int t=this->s.top();
    this->s.pop();
    this->sort();
    correctorder(this->s,t);
    }
//approach:popped the top element and put it in correct position while returning
//TC:O(N)
//SC:O(N)

//problem:count good numbers
//https://leetcode.com/problems/count-good-numbers/description/
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp = exp / 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        long long res = (modPow(5, even_positions) * modPow(4, odd_positions)) % MOD;
        return (int)res;
    }
};
//approach:used modulo exponentiation to find the total number of string ,in odd places there are 4 choices while in even there are 5 choices so found the result accordingly
//TC:O(logN)
//SC:O(1)

//
