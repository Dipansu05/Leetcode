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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> root;

        for(int i=0;i<des.size();i++){
            if(mp[des[i][0]]==0){
                TreeNode* temp = new TreeNode(des[i][0]);
                mp[des[i][0]]=temp;
            }
            if(mp[des[i][1]]==0){
                TreeNode* tt = new TreeNode(des[i][1]);
                mp[des[i][1]]=tt;
            }

            if(des[i][2]==1){
                mp[des[i][0]]->left=mp[des[i][1]];
            }else{
                mp[des[i][0]]->right=mp[des[i][1]];
            }

            if(root[des[i][0]]!=-1) root[des[i][0]]=1;
            root[des[i][1]]=-1;
        }
        int value=0;
        for(auto &it : root){
            if((it).second==1){
                value=(it).first;
                break;
            }
        }
        return mp[value];
    }
};