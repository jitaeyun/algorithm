class Solution:
    def findIntegers(self, n: int) -> int:
        sol, prev, dp = 0, 0, [1,2]
        for i in range(2,32):
            dp.append(dp[i-1]+dp[i-2])
        for i in range(30,-1,-1):
            if n&(1<<i) > 0:
                sol+=dp[i]
                if prev>0:
                    return sol
                prev=1
            else:
                prev=0
        return sol+1