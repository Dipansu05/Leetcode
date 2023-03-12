/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> m;
        while(head!=NULL){
           if( m[head]++) return true;
            else m[head]++;
            head=head->next;
        }
        return false;
    }
};