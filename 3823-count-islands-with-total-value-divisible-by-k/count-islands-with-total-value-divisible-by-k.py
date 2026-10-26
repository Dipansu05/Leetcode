class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        def dfs(i, j):
            if i<0 or j< 0 or i>=len(grid) or j>=len(grid[0]):
                return 0
            if grid[i][j]==-1 or grid[i][j]==0:
                return 0
            temp = grid[i][j]
            grid[i][j]=-1
            temp+=dfs(i+1,j)
            temp+=dfs(i-1,j)
            temp+=dfs(i,j-1)
            temp+=dfs(i,j+1)
            return temp

        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]>0:
                    
                    if dfs(i,j) % k ==0:
                        ans += 1

        return ans