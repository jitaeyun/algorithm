class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        l=0
        dp=[[0 for j in range(len(word2))] for i in range(len(word1))]
        for i in range(len(word1)):
            for j in range(len(word2)):
                if word1[i]==word2[j]:
                    dp[i][j]=1
                    if i*j > 0:
                        dp[i][j]+=dp[i-1][j-1]
                else:
                    if i>0:
                        dp[i][j]=max(dp[i][j],dp[i-1][j])
                    if j>0:
                        dp[i][j]=max(dp[i][j],dp[i][j-1])
                l=max(l,dp[i][j])
        return len(word1)+len(word2)-l*2