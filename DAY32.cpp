//Problem:reverse nodes in k groups
//https://leetcode.com/problems/reverse-nodes-in-k-group/description/
class Solution {
public:
    int length(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        if (length(head) >= k) {
            while (count < k && curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if (next != NULL) {
                head->next = reverseKGroup(next, k);
            }
            return prev;
        }
        return head;
    }
};
//approach: reversed the first k group and then did the same to the remaining linked list using recursion while the length of the remaining linked list is greater than equal to k
//TC:O(N)
//SC:O(1)

//Problem:Remove duplicates from sorted list
//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
class Solution {    
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){return NULL;}
        unordered_map <int,int>m;
        ListNode*temp=head;
        while(temp!=NULL){
            m[temp->val]++;
            temp=temp->next;
        }
        while(m[head->val]>1){
            head=head->next;
            if(head->next==NULL){
            {
                if(m[head->val]>1){return NULL;}
                else{return head;}
        }}}
      ListNode*prev=head;
      ListNode* curr=head->next;
       while(curr!=NULL){
        ListNode*next=curr->next;
        if(m[curr->val]>1){
            prev->next=next;
            curr=next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
       }
      return head;  
    }
};
//APPROACH:stored the occurance of each node value in a map and then removed the dupliucates
//TC:O(N)
//SC:O(1)
