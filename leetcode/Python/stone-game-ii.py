class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        dp = [[[0,0] for i in range(len(piles)+1)] for j in range(len(piles)+1)]
        def _traverse(f,m,idx):
            if idx>=len(piles):
                return 0
            elif dp[m][idx][f]>0:
                return dp[m][idx][f]
            sol = 0 if f==1 else 1000006
            c = 0
            for i in range(idx,min(idx+2*m,len(piles))):
                if f>0:
                    c+=piles[i]
                    sol=max(sol,c+_traverse(0,max(m,i-idx+1),i+1))
                else:
                    sol=min(sol,_traverse(1,max(m,i-idx+1),i+1))
            dp[m][idx][f]=sol
            return sol
        return _traverse(1,1,0)