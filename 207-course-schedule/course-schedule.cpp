class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        inRecursion[u]=true;
        visited[u]=true;

        for(int &v : adj[u]){
            if(!visited[v] && isCycleDFS(adj,v,visited, inRecursion)) return true;
            else if(inRecursion[v]==true) return true;
        }

        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);

        for(auto &vec : prereq){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
        }

        for(int i=0;i<n;i++){
            if(isCycleDFS(adj, i, visited, inRecursion)) return false;
        }

        return true;

    }
};