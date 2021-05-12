class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sol, mn = 0, sys.maxsize
        for p in prices:
            sol=max(sol,p-mn)
            mn=min(mn,p)
        return sol