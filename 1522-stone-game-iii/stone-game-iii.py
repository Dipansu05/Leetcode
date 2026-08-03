class Solution:
    def stoneGameIII(self, stones: List[int]) -> str:
        n = len(stones)
        dp = [-1] * (n+1)

        def solve(i):
            if i>=n:
                return 0

            if dp[i] != -1:
                return dp[i]

            res = stones[i] - solve(i+1)

            if i+1<n:
                res = max(res, stones[i]+stones[i+1]-solve(i+2))

            if i+2<n:
                res = max(res, stones[i]+stones[i+1]+stones[i+2]-solve(i+3))

            dp[i] = res
            return res

        ans = solve(0)
        if ans > 0:
            return "Alice"
        elif ans < 0:
            return "Bob"
        else:
            return "Tie"


