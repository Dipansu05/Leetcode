class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD=10**9+7
        n=len(nums)
        cnt=[0]*30
        for x in nums:
            for b in range(30):
                if x & (1<<b):
                    cnt[b] += 1

        res=0
        while k > 0:
            curr=0
            for b in range(30):
                if cnt[b] > 0:
                    cnt[b] -= 1
                    curr = ( curr | (1<<b))

            res = (res+(curr*curr)) % MOD
            k-= 1

        return res