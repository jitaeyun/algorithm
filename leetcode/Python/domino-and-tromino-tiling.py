class Solution:
    def numTilings(self, n: int) -> int:
        sol = [0,1,2,5]
        for i in range(4, n+1):
            sol.append((sol[i-1]*2+sol[i-3])%1000000007)
        return sol[n]