class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){

        queue<int> q;
        vector<int> ans;
        int count{0};

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    ans.push_back(v);
                    count++;
                    q.push(v);
                }
            }
        }
        if(count==n) return ans;
        return {};

    }
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(auto &vec: prereq){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoSort(adj,n,indegree);
    }
};