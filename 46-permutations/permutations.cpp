class Solution {
public:
    void permut(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& used){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;

            used[i]=true;
            temp.push_back(nums[i]);
            permut(nums,ans,temp,used);

            temp.pop_back();
            used[i]=false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        permut(nums,ans,temp,used);
        return ans;
    }
};