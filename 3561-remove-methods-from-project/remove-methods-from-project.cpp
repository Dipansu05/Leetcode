class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<bool> sus(n, false);

        for(auto &edge: invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        q.push(k);
        sus[k] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int &ngbr: adj[curr]){
                indegree[ngbr]--;
                if(!sus[ngbr]){
                    q.push(ngbr);
                    sus[ngbr]=true;
                }
            }
        }

        vector<int> res;
        bool cannotRemove=false;
        for(int i=0;i<n;i++){
            if(sus[i] && indegree[i]>0){
                cannotRemove = true;
                break;
            }
            if(!sus[i]) res.push_back(i);
        }

        if(cannotRemove){
            vector<int> vec(n);
            for(int i=0;i<n;i++){
                vec[i] = i;
            }
            return vec;
        }

        return res;
    }
};