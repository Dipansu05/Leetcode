
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l=1,ans,maxs=INT_MIN,t;
        while(!q.empty()){
            int n=q.size();
            t=0;
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