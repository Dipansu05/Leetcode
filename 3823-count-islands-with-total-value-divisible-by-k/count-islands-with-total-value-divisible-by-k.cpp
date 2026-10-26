class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, long long &ans){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size()) return;
        if(grid[i][j]==-1 || grid[i][j]==0) return;
        ans += grid[i][j];
        grid[i][j]=-1;
        dfs(i+1, j, grid, ans);
        dfs(i-1, j, grid, ans);
        dfs(i, j-1, grid, ans);
        dfs(i, j+1, grid, ans);
        //return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans{0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    long long  temp{0};
                    dfs(i, j, grid, temp);
                    if(temp%k==0) ans ++;
                }
            }
        }
        return ans;
    }
};