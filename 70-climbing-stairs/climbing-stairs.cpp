class Solution {
public:
    int call(int n, vector<int>& dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=call(n-1,dp)+call(n-2,dp);
        dp[n]=ans;
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return call(n, dp);
    }
};