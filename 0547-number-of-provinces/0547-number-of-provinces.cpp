class Solution
{
public:
    vector<int> g[209];

    void dfs(int src, vector<int> &vis)
    {
        vis[src] = 1;
        for (auto it : g[src])
        {
            if (!vis[it])
                dfs(it, vis);
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> vis(209, 0);
        int cnt = 0;
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                    g[i + 1].push_back(j + 1);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis);
                cnt++;
            }
        }
        return cnt;
    }
};