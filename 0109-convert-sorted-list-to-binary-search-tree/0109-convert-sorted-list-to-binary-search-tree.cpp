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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convert(ListNode* s,ListNode* e){
        if(s==e) return NULL;
        ListNode* sl=s,*fs=s;
        while(fs!=e and fs->next!=e){
            sl=sl->next;
            fs=fs->next->next;
            }
        TreeNode* ans=new TreeNode(sl->val);
        ans->left=convert(s,sl);
        ans->right=convert(sl->next,e);
        return ans;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return convert(head,NULL);
    }
};