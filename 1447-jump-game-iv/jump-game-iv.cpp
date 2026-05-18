class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0]=true;
        int ans{0};

        for(;!q.empty();ans++){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int index=q.front();
                q.pop();
                if(index==n-1) return ans;

                for(int neigh: {index-1, index+1}){
                    if(neigh>=0 && neigh<n && !vis[neigh]){
                        vis[neigh]=true;
                        q.push(neigh);
                    }
                    if(auto it=mp.find(arr[index]); it!=mp.end() && !it->second.empty()){
                        for(const int neigh: it->second){
                            if(!vis[neigh]){
                                vis[neigh]=true;
                                q.push(neigh);
                            }
                        }
                        it->second.clear();
                    }
                }
            }
        }
        return ans;
    }
};