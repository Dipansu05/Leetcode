class Solution:
    def minMoves(self, nums: List[int]) -> int:
        x=max(nums)
        ans=0
        for i in range(0,len(nums)):
            ans += x-nums[i]
        return ans