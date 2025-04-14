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
