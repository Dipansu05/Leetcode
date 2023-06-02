class Solution {
public:
    vector<int> adj[105];
    vector<int> vis;
    int cnt = 0;
    void dfs(int i)
    {
        vis[i] = 1;
        cnt++;
        for(auto it: adj[i])
        {
            if(!vis[it])
            {
                dfs(it);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& b) {
        int n = b.size();
        vis.resize(n+1);
        map<int,set<int>> mp;
        for(int i=0;i<n;i++)
        {
            int x1 = b[i][0];
            int y1 = b[i][1];
            int r1 = b[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                   int x2 = b[j][0];
                    int y2 = b[j][1];
                    if(1LL*(x1-x2)*(x1-x2)+1LL*(y1-y2)*(y1-y2)<=1LL*r1*r1) 
                    {
                        cout<<i<<" "<<j<<endl;
                        adj[i].push_back(j); 
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
                vis.clear();
                vis.resize(n+1);
                cnt = 0; 
                dfs(i);
                ans = max(ans,cnt);  
            
        }
        return ans;
        
        
    }
};