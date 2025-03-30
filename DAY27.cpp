//problem:reverse a doubly linked list
//https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list
DLLNode*solve(DLLNode * head){
    if(head==NULL || head->next==NULL){return head;}
    DLLNode* chotahead=solve(head->next);
      DLLNode* n=head->next;
         
      
          head-> next->next =head;
                  head->prev=head->next;
                  head->next=NULL;

        return chotahead;
}
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
      return  solve(head);
        
    }
};
//approach:reversed the linked list via recursion
//tc:O(N)
//SC:O(1)

//problem:delete a node in a linked list
//https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list
class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        
        if (x==1){
            head=head->next;
            
            head->prev=NULL;
            return head;
        }
        int i=1;
        Node*p=NULL;
        Node*curr=head;
        while(i<x){
            p=curr;
            curr=curr->next;
            i++;
        }
        p->next=curr->next;
        if(curr->next!=NULL){
        curr->next->prev=p;}
       
        return head;
    }
};
//Approach:traversed the linked list till the desired node and then deleted it
//TC:O(X)
//SC:O(1)
