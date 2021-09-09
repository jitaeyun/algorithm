class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        sol = 0
        dp = [[[1 for _ in range(n)] for _ in range(n)] for _ in range(4)] 
        for m in mines:
            dp[0][m[0]][m[1]]=dp[1][m[0]][m[1]]=dp[2][m[0]][m[1]]=dp[3][m[0]][m[1]]=0
        for i in range(n):
            for j in range(n):
                if j>0 and dp[0][i][j] > 0 :
                    dp[0][i][j]=dp[0][i][j-1]+1
                if j>0 and dp[1][i][n-j-1] > 0:
                    dp[1][i][n-j-1] = dp[1][i][n-j]+1
                if i>0 and dp[2][i][j] > 0:
                    dp[2][i][j] = dp[2][i-1][j]+1
                if i>0 and dp[3][n-i-1][j] > 0:
                    dp[3][n-i-1][j]=dp[3][n-i][j]+1
        for i in range(n):
            for j in range(n):
                sol=max(sol,min(dp[0][i][j],dp[1][i][j],dp[2][i][j],dp[3][i][j]))
        return sol