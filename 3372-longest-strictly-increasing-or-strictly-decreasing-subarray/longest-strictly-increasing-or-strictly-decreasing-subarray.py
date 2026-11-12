class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        maxLen=1
        inc=1
        dec=1
        for i in range(1, len(nums)):
            if nums[i]>nums[i-1]:
                inc+=1
                dec=1
            elif nums[i]<nums[i-1]:
                dec+=1
                inc=1
            else:
                dec=1
                inc=1
            maxLen=max(maxLen, max(inc,dec))

        return maxLen