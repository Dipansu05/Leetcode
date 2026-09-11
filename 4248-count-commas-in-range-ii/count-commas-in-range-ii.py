class Solution:
    def countCommas(self, n: int) -> int:
        commas = 1
        ans = 0
        lower = 1000

        while lower <= n:
            upper = 1000*lower - 1
            if upper > n:
                upper = n
            count = upper - lower + 1
            ans += commas * count
            commas += 1
            lower *= 1000

        return ans 