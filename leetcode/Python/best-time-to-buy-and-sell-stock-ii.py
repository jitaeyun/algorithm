class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sol, s, b = 0, -prices[0], 0
        for i in range(1,len(prices)):
            s, b = max(s, b-prices[i]), max(b, s+prices[i])
            sol=max(sol,b)
        return sol