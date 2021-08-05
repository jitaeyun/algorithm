class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        dp = [[0 for i in range(len(piles))] for j in range(len(piles))]
        for i in range(len(piles)):
            for j in range(0,len(piles)-i):
                if i==0:
                    dp[j][i+j]=piles[j]
                else:
                    dp[j][i+j]=max(piles[j]-dp[j+1][i+j],piles[i+j]-dp[j][i+j-1])
        return dp[0][len(piles)-1]