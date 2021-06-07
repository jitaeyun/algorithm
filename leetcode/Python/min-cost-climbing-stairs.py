class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        p1, p2 = cost[0], cost[1]
        for i in range(2,len(cost)):
            p1, p2 = p2, min(p1,p2) + cost[i]
        return min(p1,p2)