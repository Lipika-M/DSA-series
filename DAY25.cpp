//problem:Linked list insert at tail
//https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
         Node*temp=new Node(x);
         if(head==NULL){
             head=temp;
         }
        else
         {Node*curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
       curr->next=temp;}
        return head;
    }
};
//approach:simply used the curr point to reach tail and then inserting the given value
//tc:o(N)
//SC:O(1)

//
