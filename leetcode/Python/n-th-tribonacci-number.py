class Solution:
    def tribonacci(self, n: int) -> int:
        dp = list()
        for i in range(n+1):
            if i==0:
                dp.append(0)
            elif i<3:
                dp.append(1)
            else:
                dp.append(dp[i-1]+dp[i-2]+dp[i-3])
        return dp[n]