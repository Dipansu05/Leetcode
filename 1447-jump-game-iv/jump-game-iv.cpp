class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int ans{0};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int i=q.front();
                q.pop();
                if(i==n-1) return ans;
                if(i+1<n && !vis[i+1]){
                    q.push(i+1);
                    vis[i+1]=true;
                }
                if(i-1>=0 && !vis[i-1]){
                    q.push(i-1);
                    vis[i-1]=true;
                }
                for(int j: mp[arr[i]]){
                    if(!vis[j]){
                        q.push(j);
                        vis[j]=true;
                    }
                }
            mp[arr[i]].clear();
            }
            ans++;
        }
        return -1;
    }
};