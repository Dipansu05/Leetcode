class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         set<int> test;

        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){

               
                test.insert(grid[i][j]);

                for(int k=1;;k++){
                    if(i-k<0 || j-k<0 || i+k >=n || j+k>=m) break;

                    int sum{0};
                    int r=i-k;
                    int c=j;
                    for(int t=0;t<k;t++) sum+=grid[r+t][c+t];

                    r=i;
                    c=j+k;
                    for(int t=0;t<k;t++) sum+=grid[r+t][c-t];

                    r=i+k;
                    c=j;
                    for(int t=0;t<k;t++) sum+=grid[r-t][c-t];

                    r=i;
                    c=j-k;
                    for(int t=0;t<k;t++) sum+=grid[r-t][c+t];

                    test.insert(sum);

                }
            }
        }

        vector<int> ans;

        auto it=test.rbegin();
        for(int i=0;i<3 && it!=test.rend();i++,it++) ans.push_back(*it);

        return ans;
        
    }
};