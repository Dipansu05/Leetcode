class Solution {
public:
long long  fun(int i , vector<vector<int>>& q,vector<long long >&dp){
    int n = q.size();

    if(i >=n){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    long long  left = q[i][0] + fun(i+q[i][1]+1,q,dp);

    long long right  =  fun(i+1,q,dp);

    return dp[i] = max(left,right);
}
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long>dp(n,-1);
        return fun(0,q,dp);
    }
};