class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat[0].size()-1;
        int r=0;
        int c=n;
        while(c>=0 && r<=n){
            if(c==r) sum+=mat[r][c];
            else sum+=mat[r][c]+mat[r][r];
            r++;
            c--;
        }
        return sum;
    }
};