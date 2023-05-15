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
    int sz(ListNode* head){
        int x=0;
        while(head!=NULL){
        x++;
            head=head->next;
        }
        return x;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        int val1,val2;
        int x=sz(head);
        x=x-k;
        while(k!=1){
            
            temp1=temp1->next;
            k--;
        }
        val1=temp1->val;
        while(x!=0){
            temp2=temp2->next;
            x--;
        }
        val2=temp2->val;
        temp1->val=val2;
        temp2->val=val1;
        return head;
    }
};