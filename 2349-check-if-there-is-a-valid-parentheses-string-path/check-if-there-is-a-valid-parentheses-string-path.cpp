class Solution {
public:
    int m, n;
    int t[101][101][201];
    bool solve(int i, int j, int open, vector<vector<char>>& grid){
        open += (grid[i][j]=='(') ? 1:-1;
        if (open < 0) return false;
        if(t[i][j][open]!=-1) return t[i][j][open];
        if(i==m-1 && j==n-1) return t[i][j][open] = (open == 0);
        if(i+1<m){
            if(solve(i+1,j,open,grid)) return t[i][j][open] = true;
        }
        if(j+1<n){
            if(solve(i,j+1,open,grid)) return t[i][j][open] = true;
        }
        return t[i][j][open] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if((m+n-1)%2==1) return false;
        if(grid[0][0]==')' || grid[m-1][n-1]=='(') return false;
        memset(t, -1, sizeof(t));
        return solve(0,0,0,grid);
    }
};