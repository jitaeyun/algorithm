class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0]*20
        def traverse(l, h):
            sol = 0
            if l>=h:
                return 1
            if dp[h-l]>0:
                return dp[h-l]
            for i in range(l,h+1):
                sol += traverse(l,i-1)*traverse(i+1,h)
            dp[h-l]=sol
            return sol
        return traverse(1,n)
            