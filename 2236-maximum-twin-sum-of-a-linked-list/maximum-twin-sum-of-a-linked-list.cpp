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
    int pairSum(ListNode* head) {
        if(head->next->next==nullptr){
            return head->val+head->next->val;
        }

        int res{0};
        ListNode* p=head;
        ListNode* q=nullptr;
        traverse(head,p,res,q);
        return res;

        
    }

    void traverse(ListNode* head, ListNode* p, int &res, ListNode* &q){
        if(p!=nullptr){
            q=head->next;
            traverse(head->next,p->next->next,res,q);
            if(head->val+q->val>res){
                res=head->val+q->val;
            }
            q=q->next;
        }
    }
};