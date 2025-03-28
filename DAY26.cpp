//Problem:Search in a linked list
//https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list
/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
       bool found=0;
       Node*temp=head;
        while(temp!=NULL){
           if (temp->data==key){
               found=1;
               break;
           }
         
               temp=temp->next;
            
       }
       return found;
    }
};
//approach:traversed the given linked list to find if key is present or not
//TC:O(N)
//SC:O(1)
