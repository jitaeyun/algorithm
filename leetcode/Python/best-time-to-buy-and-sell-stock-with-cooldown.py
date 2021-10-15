class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        no, buy, sell, keep = [0,0], [0,0], [0,0], [0,0]
        def swaps():
            buy[0], sell[0], keep[0] = buy[1], sell[1], keep[1]
        def init(p):
            buy[0], sell[0], keep[0] = -p, 0, 0
        def update(p):
            buy[1]=max(buy[0],-p,keep[0]-p)
            keep[1]=max(keep[0],sell[0])
            sell[1]=buy[0]+p
        if not prices:
            return 0
        init(prices[0])
        for i in range(1, len(prices)):
            update(prices[i])
            swaps()
        return max(sell[1],keep[1])
            