class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sol, mx, mn = 0, [prices[-1]]*len(prices), prices[0]
        if len(prices) == 1:
            return sol
        # 1. update sol in case of only first transaction
        #    and update mx array (mx[i]: i~n max value) 
        for i in range(len(prices)-2, -1, -1):
            sol = max(sol, mx[i+1]-prices[i])
            mx[i] = max(mx[i+1], prices[i])
        # 2. update sol in case of second transaction
        # if second buy in idx i
        tr = prices[1] - prices[0]
        for i in range(2, len(prices)-1):
            tr = max(tr, prices[i-1] - mn)
            mn = min(mn, prices[i-1])
            sol = max(sol, tr + mx[i+1] - prices[i])
        return sol
            