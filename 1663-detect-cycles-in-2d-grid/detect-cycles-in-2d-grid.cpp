class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        function<bool(int,int,int,int,char)> dfs=[&](int x, int y,int px,int py,char ch){
            visited[x][y]=true;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
                if(grid[nx][ny]!=ch) continue;

                if(!visited[nx][ny]){
                    if(dfs(nx,ny,x,y,ch)) return true;
                }else{
                    if (nx!=px || ny !=py) return true;
                }
            }

            return false;
        };

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,grid[i][j])) return true;
                }
            }
        }
        return false;
    }
};