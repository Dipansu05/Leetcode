
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
        int x=sz(head);
        x=x-k;
        while(k!=1){
            temp1=temp1->next;
            k--;
        }
        while(x!=0){
            temp2=temp2->next;
            x--;
        }
        swap(temp1->val,temp2->val);
        return head;
    }
};