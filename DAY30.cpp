//problem 1: sort linked list
 //https://leetcode.com/problems/sort-list/
 class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
ListNode*merge(ListNode* left,ListNode*right){
if(right==NULL){
        return left;
}
if(left==NULL){
        return right;
}
ListNode*ans=new ListNode(-1);
ListNode *temp=ans;
while(right!=NULL && left!=NULL){
    if(left->val < right->val){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    else  {
        temp->next=right;
        temp=right;
        right=right->next;
    }}
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
      while(left!=NULL){
        temp->next=left;
        temp=left;
      left=left->next;
    }
    return ans->next;
}
    
    ListNode* sortList(ListNode* head) {
      if(head==NULL || head->next==NULL){
        return head;
      }  
    ListNode*mid=middleNode(head);
    ListNode*left=head;
    ListNode*right=mid->next;
    mid->next=NULL;
    left=sortList(left);
    right=sortList(right);
   return merge(left,right);
    }
};
//approach:applied merge sort algorithm for linked list
//TC:O(Nlog N)
//SC:O(1)

//Problem :remove nth npde from the end at linked list
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL  ){
            return head;
        }
         if(head->next==NULL && n==1){
            return NULL;
         }
        int len=0;
        ListNode *temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int pos=len-n+1;
        if (pos==1){return head->next;}
        int i=0;
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(i<pos-1){
         prev=curr;
         curr=curr->next;
         i++;
        }
        if(curr!=NULL && prev!=NULL){
        prev->next=curr->next;
         curr->next=NULL;}
        else if(curr==NULL && prev!=NULL){
            prev->next=NULL;
        }
       
          return head;
    }
  
};
//Approach:calculated the positiom of the node to be deleted from the begining andt then deleted it
//TC:O(p)
//SC:O(1)
