class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        sol, dp = 0, [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j]=='0':
                    continue
                elif i==0 or j==0:
                    dp[i][j]=1
                else:
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
                sol = max(sol, dp[i][j])
        return sol*sol