class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [0]*(n+1)
        for i in range(1, n+1):
            j, k = 1, 1
            while k <= i:
                if dp[i - k] == 0:
                    dp[i] = 1
                    break
                j, k = j+1, (j+1)*(j+1)
        return dp[n] == 1