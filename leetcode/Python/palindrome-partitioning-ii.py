class Solution:
    def minCut(self, s: str) -> int:
        dp, sol, l = [[0 for i in range(len(s))] for j in range(len(s))], [0]*len(s), len(s)
        # 1. find dp (dp[i][j] --> in case of palindrome from i to j)
        for i in range(l):
            for j in range(l-i):
                if s[j]==s[i+j]:
                    dp[j][i+j]=1 if i<=1 else dp[j+1][i+j-1]
        # 2. find sik (sol[i] --> in case of min cut from 0 to i)
        for i in range(1,l):
            sol[i] = 0 if dp[0][i]==1 else i
            for j in range(i):
                if dp[j+1][i]==1:
                    sol[i]=min(sol[i],sol[j]+1)
        # 3. return sol[len-1] --> in case of min cut from 0 to len-1
        return sol[l-1]