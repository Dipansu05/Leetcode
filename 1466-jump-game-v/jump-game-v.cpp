class Solution {
public:
    int n;
    int dfs(vector<int>& arr, int i, vector<int>& dp, int d){
        if(dp[i]!=-1) return dp[i];
        int ans{1};

        for(int j=i+1;j<=min(n-1, i+d);j++){
            if(arr[j]>=arr[i]) break;
            ans=max(ans, 1+dfs(arr, j, dp, d));
        }

        for(int j=i-1;j>=max(0, i-d);j--){
            if(arr[j]>=arr[i]) break;
            ans=max(ans, 1+dfs(arr, j, dp, d));
        }

        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        int ans{1};
        vector<int> dp(n, -1);
        for(int i=0;i<n;i++){
            ans=max(ans, dfs(arr, i, dp, d));
        }
        return ans; 
    }
};