class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.length(),i,j,ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        for(i = 1; i<=n; i++){
            for(j = 1; j<=n; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
    int minInsertions(string s) {
        return s.length()-longestPalindromeSubseq(s);
    }
};