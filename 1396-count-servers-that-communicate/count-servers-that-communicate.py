class Solution(object):
    def countServers(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n=len(grid)
        m=len(grid[0])

        row=[0]*n
        col=[0]*m
        for i in range(0,n):
            for j in range(0,m):
                if grid[i][j]==1:
                    row[i]+=1
                    col[j]+=1

        ans = 0
        for i in range (0,n):
            for j in range (0,m):
                if grid[i][j]==1 and (row[i]>1 or col[j]>1):
                    ans += 1

        return ans       