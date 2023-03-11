
class Solution {
public:
    TreeNode* convert(ListNode* start, ListNode* end){
        if(start==end) return nullptr;
        
        ListNode* slow=start;
        ListNode* fast=start;
        
        while(fast!=end && fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
            }
        
        TreeNode* ans=new TreeNode(slow->val);
            ans->left=convert(start,slow);
            ans->right=convert(slow->next,end);
        
            return ans;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        return convert(head,nullptr);
    }
};