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
