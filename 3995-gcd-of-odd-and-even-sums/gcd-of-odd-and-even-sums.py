class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        cnt = 1
        odd = 1
        even = 2
        even_sum = 2
        odd_sum = 1
        while cnt < n :
            odd += 2
            even += 2
            even_sum += even
            odd_sum += odd
            cnt += 1

        return gcd(even_sum, odd_sum)