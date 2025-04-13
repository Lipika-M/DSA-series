//Problem:Copy list with random pointers
//https://leetcode.com/problems/copy-list-with-random-pointer/description/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void insertattail(Node* &head,Node*&tail,int data){
    Node*temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}
    Node* copyRandomList(Node* head) {
        Node*copyhead=NULL;
        Node*copytail=copyhead;
        Node*head1=head;
         while(head1!=NULL){
            int val=head1->val;
            insertattail(copyhead,copytail,val);
            head1=head1->next;
        }
        head1=head;
        Node*head2=copyhead;
        unordered_map<Node*,Node*>m;
        while(head1!=NULL && head2!=NULL){
            m[head1]=head2;
            head1=head1->next;
            head2=head2->next;
        }
        head1=head;
        head2=copyhead;
       while(head1!=NULL && head2!=NULL){
            head2->random=m[head1->random];
            head1=head1->next;
            head2=head2->next;
        } 
        return copyhead;
    }
};
//APPROACH: created a mapping from original list to copy and then copied the random pointer
//TC:O(N)
//SC:O(N)
