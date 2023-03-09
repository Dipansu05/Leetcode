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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
     ListNode* s=head,*f=head,*ans=head;
     while(f->next && f->next->next){
         s=s->next;
         f=f->next->next;
         if(f==s){
             while(ans!=s){
                 s=s->next;
                 ans=ans->next;
             }
             return ans;
         }
     }
        return NULL;
    }
};