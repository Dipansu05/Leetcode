class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)

        for i in range(n):
            s = set()
            for j in range(i, n):
                s.add(nums[j])
                d = len(s)
                res += d*d

        return res