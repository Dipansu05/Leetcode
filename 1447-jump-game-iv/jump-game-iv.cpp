class Solution {
public:
    int minJumps(vector<int>& arr) {
                int n=arr.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
            
        }
        queue<int> q;
        vector<bool> v(n);
        v[0]=true;
        int ans=0;
        q.push(0);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int i=q.front();
                q.pop();
                if(i==n-1) return ans;
                if(i+1<n and !v[i+1]){
                q.push(i+1);
                v[i+1]=true;
                }
                if(i-1>=0 and !v[i-1]){
                q.push(i-1);
                v[i-1]=true;
                }
                for(int j:m[arr[i]]){
                if(!v[j]){
                    q.push(j);
                    v[j]=true;
                }
            }
            m[arr[i]].clear();
            }
         ans++;   
        }
        return -1;
    }
};