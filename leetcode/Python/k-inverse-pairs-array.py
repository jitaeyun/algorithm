class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 1000000007
        dp = [[0 for _ in range(k+1)] for _ in range(2)]
        dp[1][0]=dp[0][0]=1
        for i in range(1,n+1):
            for j in range(1,min(k,(i*i-1)//2)+1):
                dp[1][j]=dp[1][j-1]+dp[0][j]
                if j>=i:
                    dp[1][j]-=dp[0][j-i]
                dp[1][j]=(dp[1][j]+MOD)%MOD
            dp[0][:]=dp[1][:]
        return dp[1][k]