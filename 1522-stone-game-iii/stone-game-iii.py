class Solution:
    def stoneGameIII(self, stoneValues: List[int]) -> str:
        n = len(stoneValues)
        dp = [0] * (n+1)
        for i in range(n-1, -1, -1):
            dp[i] = float("-inf")
            total = 0

            for j in range(i, min(n, i+3)):
                total += stoneValues[j]
                dp[i] = max(dp[i], total-dp[j+1])
        
        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"