class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m-1,-1,-1):
            for j in range(n-1, -1, -1):
                if i==m-1 and j==n-1:
                    dp[i][j]=max(1-dungeon[i][j],1)
                elif i==m-1:
                    dp[i][j]=max(dp[i][j+1]-dungeon[i][j],1)
                elif j==n-1:
                    dp[i][j]=max(dp[i+1][j]-dungeon[i][j],1)
                else:
                    dp[i][j]=min(max(dp[i][j+1]-dungeon[i][j],1), max(dp[i+1][j]-dungeon[i][j],1))
        return dp[0][0]