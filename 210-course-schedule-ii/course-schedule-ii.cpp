class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        vector<int> adj[n];

        for(auto x: pre) adj[x[1]].push_back(x[0]);

        vector<int> ind(n,0);
        vector<int> topo;
        queue<int> q;

        for(int i=0;i<n;i++){
            for(auto j: adj[i]) ind[j]++;
        }

        for(int i=0;i<n;i++){
            if(!ind[i]) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i: adj[node]){
                ind[i]--;
                if(!ind[i]) q.push(i);
            }
        }
        if(topo.size()==n) return topo;
        return {}; 
    }
};