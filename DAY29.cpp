//porblem:palindromic linked list
//https://leetcode.com/problems/palindrome-linked-list/
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
   ListNode* reverse(ListNode* & head){
       ListNode* p=NULL;
        ListNode* curr=head; 
        while(curr!=NULL){
            ListNode* n=curr->next;
            curr->next=p;
            p=curr;
            curr=n; 
        }
        return p;
         }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){return true;}
        ListNode* mid=middleNode( head);
        ListNode *right=mid->next;
        mid->next==NULL;
        right =reverse(right);
        ListNode*temp1=head;
        ListNode*temp2=right;
        while( temp2!=NULL){
            if(temp1->val !=temp2->val){return false;}
            else
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};
//approach:we   divided the linked list into left and right part from the middle and the reversed the second part and checked whether the left and the right part are the same
//TC:O(N)
//SC:O(1)


//problem:count the number of nodes in the cycle
//https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop
 
class Solution {
  public:
   
    Node* hasCycle(Node *head) {
        if(head==NULL){
            return NULL;
        }
        Node*slow=head;
        Node*fast=head;
       while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return slow;
            }
        }
        return NULL;
    }
    Node* getstart(Node*head){
        if(head==NULL){
            return NULL;
        }
    
    Node*intersection=hasCycle(head);
    if(intersection==NULL){return NULL;}
       Node*slow=head;
       while(slow!=intersection){
         slow=slow->next;
         intersection=intersection->next;
         
       }
       return slow;
        }
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
       if(hasCycle(head)==NULL){
        return  0;   
       }
       int count=0;
       Node*start=getstart(head);
       Node*temp=start;
       while(temp->next!=start ){
           temp=temp->next;
           count++;
       }
       return count+1;
    }
};
//approach:first found if the loop is present or not and then if present then found the start of the loop and then incremented the cound till the loop ends
//TC:O(N)
//SC:O(1)
