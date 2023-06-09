class Solution {
public:
    int cnt(int l,int r,vector<int> g){
        int ans=-1,m;
        while(l<=r){
        m=l+(r-l)/2;
            if(g[m]<0){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            int in=cnt(0,n-1,grid[i]);
            if(in!=-1) ans+=n-in;
        }
        return ans;
    }
};