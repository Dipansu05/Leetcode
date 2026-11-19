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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        vector<int> stack;
        ListNode* temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=ans.size()-1;i>=0;i--){
            auto val=ans[i];
            while(!stack.empty() && stack.back() <= ans[i]) stack.pop_back();
            ans[i] = stack.empty() ? 0 : stack.back();
            stack.push_back(val);
        }
        return ans;
    }
};