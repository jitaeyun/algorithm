class Solution:
    def numSquares(self, n: int) -> int:
        dp = [0]*(n+1)
        for i in range(1,n+1):
            j, k = 1, 1
            dp[i]=dp[i-1]+1
            while j<=i:
                dp[i]=min(dp[i], dp[i-j]+1)
                k+=1
                j=k*k
        return dp[n]