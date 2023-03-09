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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* f=headA, *s=headB;
        int i=0,j=0;
        while(f){
            f=f->next;
            i++;
        }
        while(s){
            s=s->next;
            j++;
        }
        f=headA,s=headB;
        if(i>j){
            int d=i-j;
            while(d){
                f=f->next;
                d--;
            }
            while(f){
                if(f==s) return f;
                f=f->next;
                s=s->next;
               
            }
        }
        else{
            int d=j-i;
            while(d){
                s=s->next;
                d--;
            }
            while(s){
                if(f==s) return f;
                f=f->next;
                s=s->next;
                }
        }
        return NULL;
    }
};