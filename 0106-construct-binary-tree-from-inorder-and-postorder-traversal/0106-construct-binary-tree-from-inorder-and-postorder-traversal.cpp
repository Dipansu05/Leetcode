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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& ump, int& rootIdx, int left, int right) {
        if(left > right) return NULL;
        int pivot = ump[postorder[rootIdx]];
        TreeNode* node = new TreeNode(postorder[rootIdx]);
        rootIdx--;
        node->right = buildTreeHelper(inorder, postorder, ump, rootIdx, pivot+1, right);
        node->left = buildTreeHelper(inorder, postorder, ump, rootIdx, left, pivot-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int> m;
        for(int i=0;i<in.size();i++) m[in[i]]=i;
        int rootid=post.size()-1;
        return  buildTreeHelper(in,post,m,rootid,0,in.size()-1);
    }
};