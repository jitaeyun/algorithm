class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        dp = [[0 for i in range(len(stones))] for j in range(len(stones))]
        def _traverse(l,r,s):
            if l>=r:
                return 0
            if dp[l][r]>0:
                return dp[l][r]
            dp[l][r]=max(s-stones[l]-_traverse(l+1,r,s-stones[l]), s-stones[r]-_traverse(l,r-1,s-stones[r]))
            return dp[l][r]
        return _traverse(0,len(stones)-1,sum(stones))