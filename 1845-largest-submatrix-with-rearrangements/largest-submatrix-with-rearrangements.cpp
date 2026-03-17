class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans{0};
        vector<int> h(col,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==1) h[j]++;
                else h[j]=0;
            }
            vector<int> sh = h;
            sort(sh.rbegin(), sh.rend());
            for(int j=0;j<col;j++){
                if(sh[j]==0) break;
                ans=max(ans,(j+1)*sh[j]);
            }
        }

        return ans;
    }
};