//problem:middle of linked list
//https://leetcode.com/problems/middle-of-the-linked-list/description/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
//Approach:we used a slow and fast pointer and when the fast would have reached the end the slow would be at the middle node
//TC:O(N)
//SC:O(1)


//problem:linked list cycle detection
//https://leetcode.com/problems/linked-list-cycle/description/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode*slow=head;
        ListNode*fast=head;
       while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};
//approach:used a floyd cycle detection algorithm to detect if a cycle is present or not
//TC:O(N)
//SC:O(1)
