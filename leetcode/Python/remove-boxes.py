class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        dp = [[[0 for _ in range(len(boxes))] for _ in range(len(boxes))] for _ in range(len(boxes))]
        def _solve(l,r,k):
            if l>r:
                return 0
            if dp[l][r][k]>0:
                return dp[l][r][k]
            dp[l][r][k]=_solve(l+1,r,0)+(k+1)*(k+1)
            for i in range(l+1,r+1):
                if boxes[l]==boxes[i]:
                    dp[l][r][k]=max(dp[l][r][k],_solve(l+1,i-1,0)+_solve(i,r,k+1))
            return dp[l][r][k]
        return _solve(0,len(boxes)-1,0)