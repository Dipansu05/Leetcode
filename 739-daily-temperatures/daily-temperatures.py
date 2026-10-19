class Solution:
    def dailyTemperatures(self, nums: list[int]) -> list[int]:
        stack = []
        n = len(nums)
        ans = [0] * n

        for i in range(0, n):
            element = nums[i]
            while stack and element>nums[stack[-1]]:
                x = stack.pop()
                ans[x] = i - x
            stack.append(i)

        return ans