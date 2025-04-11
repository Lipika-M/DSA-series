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


//problem:add two numbers represented by a linked list
//https://leetcode.com/problems/add-two-numbers/description/
class Solution {
public:
    void insertattail(ListNode*& anshead, ListNode*& anstail, int digit) {
        ListNode* temp = new ListNode(digit);
        if (anshead == NULL) {
            anshead = temp;
            anstail = temp;
            return;
        } else
            anstail->next = temp;
        anstail = temp;
    }
    ListNode* solve(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* anshead = NULL;
        ListNode* anstail = anshead;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = 0;
            if (l1 != NULL) {
                val1 = l1->val;
            }
            int val2 = 0;
            if (l2 != NULL) {
                val2 = l2->val;
            }
            sum = val1 + val2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            insertattail(anshead, anstail, digit);

            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        return anshead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = solve(l1, l2);
        return ans;
    }
};
//Approach:added numbers of each node and then returned the answer node
//TC:O(N)
//SC:O(1)
