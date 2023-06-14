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
    vector<int> temp;
    void trav(TreeNode* root){
        if(!root) return;
        trav(root->left);
        temp.push_back(root->val);
        trav(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        trav(root);
        int ans=INT_MAX;
        for(int i=0;i<temp.size()-1;i++){
            if(abs(temp[i]-temp[i+1])<ans) ans=abs(temp[i]-temp[i+1]);
        }
        return ans;
    }
};