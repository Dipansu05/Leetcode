class Solution {
public:
    void dfs_graph(vector<vector<int>> &graph, int u, vector<bool> &vis){
        vis[u]=true;
        for(auto &v: graph[u]){
            if(!vis[v]) dfs_graph(graph,v,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);

        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int components{0};
        for(int u=0;u<n;u++){
            if(!vis[u]){
                dfs_graph(graph,u,vis);
                components++;
            }
        }
        return components-1;
    }
};