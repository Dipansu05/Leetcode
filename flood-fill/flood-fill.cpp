class Solution {
public:
   void bfs(vector<vector<int>>& image,int i,int j,int val,int col){
        if(i>=image.size() || j>=image[0].size() || i<0 || j<0 || image[i][j]==col || image[i][j]!=val) return;
        image[i][j]=col;
        
        bfs(image,i+1,j,val,col);
        bfs(image,i-1,j,val,col);
        bfs(image,i,j-1,val,col);
        bfs(image,i,j+1,val,col);
       
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int val=image[sr][sc];
        bfs(image,sr,sc,val,color);
        return image;
    }
};