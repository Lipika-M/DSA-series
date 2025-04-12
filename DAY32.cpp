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
