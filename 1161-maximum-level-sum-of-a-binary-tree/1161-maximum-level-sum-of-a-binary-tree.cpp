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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxs=INT_MIN;
        int l=1,ans;
        while(!q.empty()){
            int n=q.size();
            int t=0;
            while(n--){
                TreeNode* tm=q.front();
                q.pop();
                t+=tm->val;
                if(tm->left) q.push(tm->left);
                if(tm->right) q.push(tm->right);
            }
            if(t>maxs){
                maxs=t;
                ans=l;
            }
            l++;
        }
        return ans;
    }
};