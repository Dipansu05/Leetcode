
    // void solve(int i, int j, int n, int m, int ans,
    //            vector<vector<int>>& vis,
    //            vector<vector<int>>& grid,
    //            vector<int>& store ){
        
    //     if(i == n-1 && j == m-1){
    //         store.push_back(ans);
    //         return;
    //     }
    //     if(j+1<m && !vis[i][j]){
    //         vis[i][j]=1;
    //         solve(i, j+1, n, m, ans*grid[i][j], vis,grid, store);
    //         vis[i][j]=0;
    //     }

    //     if(i+1<n && !vis[i][j]){
    //         vis[i][j]=1;
    //         solve(i+1, j, n, m, ans*grid[i][j], vis,grid, store);
    //         vis[i][j]=0;
    //     }
    // }

    class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> maxP(n, vector<long long>(m));
        vector<vector<long long>> minP(n, vector<long long>(m));

        maxP[0][0] = minP[0][0] = grid[0][0];

        // first row
        for(int j = 1; j < m; j++){
            maxP[0][j] = minP[0][j] = maxP[0][j-1] * grid[0][j];
        }

        // first column
        for(int i = 1; i < n; i++){
            maxP[i][0] = minP[i][0] = maxP[i-1][0] * grid[i][0];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                long long val = grid[i][j];

                long long a = maxP[i-1][j] * val;
                long long b = minP[i-1][j] * val;
                long long c = maxP[i][j-1] * val;
                long long d = minP[i][j-1] * val;

                maxP[i][j] = max({a, b, c, d});
                minP[i][j] = min({a, b, c, d});
            }
        }

        long long res = maxP[n-1][m-1];

        if(res < 0) return -1;
        return res % MOD;
    }
};
