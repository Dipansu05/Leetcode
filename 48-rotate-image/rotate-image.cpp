class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp{matrix};
        int n=matrix.size(),k;
        for(int i=0;i<n;i++){
            k=n-1;
            for(int j=0;j<n;j++){
                matrix[i][j]=temp[k][i];
                k--;
            }
        }
    }
};