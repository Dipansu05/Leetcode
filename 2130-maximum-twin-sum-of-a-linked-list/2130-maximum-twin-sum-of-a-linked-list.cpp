class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* next;
        
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
       
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverseList(slow);
        int ans=INT_MIN;
        
        while(slow!=NULL){
            ans=max(ans,slow->val+head->val);
            slow=slow->next;
            head=head->next;    
        }
        return ans;
        
		
        
    }
};