
class Solution {
public:
    int solve(int size, int low, int high, int zero, int one, vector<int>& dp)
    {
        //base cases
        if(size>high) return 0;
        if(size == high) return 1;

        //dp base case
        if(dp[size] != -1) return dp[size];

        //recursive cases
        int zRec = solve(size+zero, low, high, zero, one, dp);
        int oRec = solve(size+one, low, high, zero, one, dp);

        if(size>=low) return dp[size] = (1 + zRec + oRec)%1000000007;
        return dp[size] = (zRec + oRec)%1000000007;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int> dp(high, -1);
        return solve(0, low, high, zero, one, dp);
    }
};