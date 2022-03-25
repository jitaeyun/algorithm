class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs)//2
        dp = [[10000000 for _ in range(n+1)] for _ in range(n+1)]
        dp[0][0] = 0
        for i in range(len(costs)):
            k = i
            for j in range(i+1):
                k = i - j
                if j > n or k > n:
                    continue
                if j+1 <=n:
                    dp[j+1][k] = min(dp[j+1][k], dp[j][k]+costs[i][0])
                if k+1 <= n:
                    dp[j][k+1] = min(dp[j][k+1], dp[j][k]+costs[i][1])
        return dp[-1][-1]