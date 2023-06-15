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
    void levelor(vector<vector<int>> &ans, TreeNode* root, int level){
        if(root==NULL) return;
        if(level==ans.size()) ans.push_back({root->val});
        else
            ans[level].push_back(root->val);
            levelor(ans,root->left,level+1);
            levelor(ans,root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> ans;
        levelor(ans,root,0);
        int a=INT_MIN,d=0;
        for(int i=0;i<ans.size();i++){
            int t=0;
            for(int j=0;j<ans[i].size();j++){
                t+=ans[i][j];
            }
            if(t>a){
                a=t;
                d=i+1;
            }
        }
        return d;
    }
};