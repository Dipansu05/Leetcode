class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minBuy = prices[0]
        maxP = 0

        for i in range (len(prices)):
            maxP = max(maxP, prices[i]-minBuy)
            minBuy = min(minBuy, prices[i])

        return maxP