class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &mp, int u, vector<bool> &vis, int &Size){
        vis[u]=true;
        Size++;
        for(auto &x : mp[u]){
            if(!vis[x]) dfs(mp,x,vis,Size);
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> mp;
        for(auto &vec: edges){
            mp[vec[0]].push_back(vec[1]);
            mp[vec[1]].push_back(vec[0]);
        }

        long long ans{0};
        long long rem{n};

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int Size{0};
                dfs(mp,i,vis,Size);
                ans+=Size*(rem-Size);
                rem-=Size;
            }
        }
        return ans;
    }
};