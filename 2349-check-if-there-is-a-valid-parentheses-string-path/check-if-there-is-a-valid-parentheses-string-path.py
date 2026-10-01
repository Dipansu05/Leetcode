class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])

        if (m+n-1)%2==1:
            return False

        if grid[0][0] == ')' or grid[m-1][n-1] == '(':
            return False

        @lru_cache(None)
        def dfs(i,j,open_count):
            open_count += 1 if grid[i][j] == '(' else -1
            if open_count < 0:
                return False
            if i==m-1 and j==n-1:
                return open_count == 0
            return (
                (i+1<m and dfs(i+1,j,open_count)) or
                (j+1<n and dfs(i,j+1,open_count))
            )

        return dfs(0,0,0)