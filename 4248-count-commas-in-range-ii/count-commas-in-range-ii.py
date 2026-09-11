class Solution:
    def countCommas(self, n: int) -> int:
        start = 1000
        ans = 0

        while start <= n:
            ans += n - start + 1
            start *= 1000

        return ans