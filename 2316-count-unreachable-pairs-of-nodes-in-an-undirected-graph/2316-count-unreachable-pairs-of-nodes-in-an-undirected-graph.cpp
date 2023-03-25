class Solution {
public:
    void solve(int s,vector<vector<int>> &g,vector<bool> &v,long long int& k){
        if(v[s])return;
        k++;
        v[s] = true;
        for(auto &i: g[s]){
            solve(i,g,v,k);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<bool> v(n,false);
        long long int ans = 0;
        for(auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        long long int k = 0;
        for(int i = 0; i < n;i++){
            if(v[i])continue;
            k = 0;
            solve(i,g,v,k);
            ans += (k*(n-k));
        }
        return (ans>>1);
    }
};