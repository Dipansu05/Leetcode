class Solution {
public:
int f(int ind, vector<int>& nums, vector<int>& dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];
    int pick = nums[ind] + f(ind - 2 , nums, dp);
    int notPick = 0 + f(ind - 1, nums, dp);
    return dp[ind] = max(pick, notPick);
}
    int rob(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> include(n);
        // vector<int> exclude(n);
        // //int include[n];
        // //int exclude[n];
        // include[0]=nums[0];
        // exclude[0]=0;

        // for(int i=1;i<n;i++){
        //     include[i] = nums[i] + exclude[i-1];
        //     exclude[i] =max(include[i-1], exclude[i-1]);
        // }

        // return max(include[n-1], exclude[n-1]);

        int n= nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};