/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        head = new ListNode(-1, head);
        ListNode *prev1 = head, *prev2 = head, *curr = head;
        while (--k) {
            prev1 = prev1->next;
            curr = curr->next;
        }
        curr = curr->next;
        while (curr->next) {
            prev2 = prev2->next;
            curr = curr->next;
        }
        if (prev1->next == prev2) {
            curr = prev2->next;
            prev1->next->next = prev2->next->next;
            curr->next = prev1->next;
            prev1->next = curr;
            return head->next;
        }
        curr = prev1->next;
        prev1->next = prev2->next;
        prev1 = prev2->next->next;
        prev2->next->next = curr->next;
        prev2->next = curr;
        curr->next = prev1;
        return head->next;
    }
    
};