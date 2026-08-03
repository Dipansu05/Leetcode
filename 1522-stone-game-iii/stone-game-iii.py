class Solution:
    def stoneGameIII(self, stones: List[int]) -> str:
        n = len(stones)
        t = [0] * (n+1)

        for i in range(n-1,-1, -1):
            t[i] = stones[i] - t[i+1]
            if i + 2 <= n:
                t[i] = max(t[i], stones[i]+stones[i+1]-t[i+2])
            if i + 3 <= n:
                t[i] = max(t[i], stones[i]+stones[i+1]+stones[i+2]-t[i+3])

        res = t[0]
        if res > 0:
            return "Alice"
        elif res<0:
            return "Bob"
        else:
            return "Tie"
        