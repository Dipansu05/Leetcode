class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        
        def dfs(i, j):
            if i<0 or j<0 or i>=len(grid) or j>=(len(grid[0])):
                return False

            if grid[i][j]==1 or grid[i][j]==2:
                return True

            grid[i][j]=2

            isLeft=dfs(i,j-1)
            isRight=dfs(i,j+1)
            isTop=dfs(i-1,j)
            isBottom=dfs(i+1,j)

            return isLeft and isRight and isTop and isBottom

        ans = 0
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                if grid[i][j]==0 and dfs(i,j):
                    ans += 1

        return ans