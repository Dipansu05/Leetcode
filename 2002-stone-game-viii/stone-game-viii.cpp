class Solution {
public:
    int n;
    
    int t[100001];

    int stoneGameVIII(vector<int>& stones) {
     memset(t, -1, sizeof(t));
     n=stones.size();
     vector<int> pref(n, 0);
     pref[0]=stones[0];
     for(int i=1;i<n;i++){
        pref[i]=stones[i]+pref[i-1];
     }
     vector<int> t(n,0);
     t[n-1]=pref[n-1];
     for(int i=n-2;i>=1;i--){
        int take=pref[i]-t[i+1];
        int skip=t[i+1];
        t[i] = max(take, skip);
     }
     return t[1];
    }
};