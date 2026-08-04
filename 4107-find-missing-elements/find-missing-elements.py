class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        ans = []
        temp = [-1] * 101
        sm = float('inf')
        lg = float('-inf')

        for n in nums:
            if n < sm:
                sm = n
            if n > lg:
                lg = n
            temp[n] = 1

        for i in range(sm, lg):
            if temp[sm] == -1:
                ans.append(sm)
            sm += 1

        return ans
        