class Solution {
public:
    void solve(int s,vector<bool> &vis,vector<bool> &stv,vector<int> &dis,int &ans,vector<int> &g,int k){
        if(s != -1){
            if(!vis[s]){
                vis[s] = true;
                stv[s] = true;
                dis[s] = k;
                solve(g[s],vis,stv,dis,ans,g,k+1);
            }else if(stv[s]){
                ans = max(ans,k-dis[s]);
            }
            stv[s] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n,false),sametimevis(n,false);
        vector<int> dis(n,-1);
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                solve(i,vis,sametimevis,dis,ans,edges,0);
            }
        }
        return ans;
    }
};