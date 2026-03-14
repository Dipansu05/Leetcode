class Solution {
public:
    void combination(int index,vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target){
        if(index==candidates.size()){
            if(target==0) ans.push_back(temp);
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            combination(index,candidates, ans,temp,target-candidates[index]);
            temp.pop_back();
        }
        combination(index+1,candidates, ans, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        combination(0,candidates,ans,temp,target);
        return ans;
    }
};