class Solution:

    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0

        def digitSum(n):
            total=0

            while n>0 :
                total += n%10
                n //= 10

            return total

        sorted_nums = sorted(nums, key=lambda x: (digitSum(x), x))
        val = {}

        for i in range(n):
            val[nums[i]]=i

        for i in range(n):
            expected=sorted_nums[i]
            current=nums[i]

            if expected == current:
                continue

            idx = val[expected]
            nums[i]=expected
            nums[idx]=current

            val[expected]=i
            val[current]=idx

            count += 1

        return count