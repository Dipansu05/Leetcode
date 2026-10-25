class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size()) return false;
        if(grid[i][j]== 1 || grid[i][j]==2) return true;
        grid[i][j]=2;
        bool isLeft   = dfs(i,j-1,grid);
        bool isRight  = dfs(i,j+1,grid);
        bool isTop    = dfs(i-1,j,grid);
        bool isBottom = dfs(i+1,j,grid);
        return isLeft && isRight && isTop && isBottom;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans{0};
        for(int i=0;i<grid.size(); i++){
            for(int j=0;j<grid[0].size(); j++){
                if(grid[i][j]==0 && dfs(i,j,grid)) ans++;
            }
        }
        return ans;
    }
};