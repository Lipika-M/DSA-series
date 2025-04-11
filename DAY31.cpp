//Problem:Remove linked list elements
//https://leetcode.com/problems/remove-linked-list-elements/description/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL || head->next==NULL && head->val==val){return NULL;}
        while(head->val==val && head!=NULL ){
            if (head->next==NULL){
                return NULL;
            }
           head=head->next;
        }
         ListNode* curr=head->next;
         ListNode*prev=head;
        
        while(curr!=NULL){
           if(curr->val==val){
                prev->next=curr->next;
           }
            
           else 
          { prev=curr;}
           curr=prev->next;
        }
        return head;
    }
};
//APPROACH:deleted the nodes with value equal to given value
//TC:O(N)
//SC:O(1)
