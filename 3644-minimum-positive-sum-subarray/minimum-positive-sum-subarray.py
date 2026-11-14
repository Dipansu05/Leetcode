class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        ans = float('inf')
        n = len(nums)
        for i in range(0, n):
            sum = 0
            for j in range (i, n):
                sum += nums[j]
                length = j-i+1
                if sum > 0 and length<=r and length>=l:
                    ans = min(ans, sum)

        return -1 if ans==float('inf') else ans