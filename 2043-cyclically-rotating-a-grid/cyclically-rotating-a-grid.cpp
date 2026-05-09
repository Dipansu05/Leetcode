class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int layers=min(m,n) /2;

        for(int layer=0;layer<layers;layer++){
            int top=layer;
            int left=layer;
            int bottom=m-layer-1;
            int right=n-layer-1;
            vector<int> vals;

            for(int i=left;i<=right;i++){
                vals.push_back(grid[top][i]);
            }

            for(int i=top+1;i<=bottom-1;i++){
                vals.push_back(grid[i][right]);
            }

            for(int i=right;i>=left;i--){
                vals.push_back(grid[bottom][i]);
            }

            for(int i=bottom-1;i>=top+1;i--){
                vals.push_back(grid[i][left]);
            }

            int sz=vals.size();
            int start=k%sz;
            int idx=start;

            for(int j=left;j<=right;j++){
                grid[top][j]=vals[idx];
                idx++;
                if(idx==sz) idx=0; 
            }

            for(int j=top+1;j<=bottom-1;j++){
                grid[j][right]=vals[idx];
                idx++;
                if(idx==sz) idx=0; 
            }

            for(int j=right;j>=left;j--){
                grid[bottom][j]=vals[idx];
                idx++;
                if(idx==sz) idx=0; 
            }

            for(int j=bottom-1;j>=top+1;j--){
                grid[j][left]=vals[idx];
                idx++;
                if(idx==sz) idx=0; 
            }
        }

        return grid;
    }
};