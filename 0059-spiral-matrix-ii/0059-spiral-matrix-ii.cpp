class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int sr=0,sc=0,er=n-1,ec=n-1;
        int i=1;
        
        while(sr<=er && sc<=ec){
            for(n=sc;n<=ec;n++){
                ans[sr][n]=i;
                i++;
            }
            sr++;
            for(n=sr;n<=er;n++){
                ans[n][ec]=i;
                i++;
            }
            ec--;
            for(n=ec;n>=sc;n--){
                ans[er][n]=i;
                i++;
            }
            er--;
            for(n=er;n>=sr;n--){
                ans[n][sc]=i;
                i++;
            }
            sc++;
        }
        return ans;
    }
};