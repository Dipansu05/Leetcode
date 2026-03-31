class Solution {
public:
    int cal(vector<int>& nums, int i, vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+cal(nums,i-2,dp);
        int not_pick=cal(nums,i-1,dp);
        int ans = max(pick, not_pick);
        dp[i]=ans;
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return cal(nums,nums.size()-1,dp);
    }
};