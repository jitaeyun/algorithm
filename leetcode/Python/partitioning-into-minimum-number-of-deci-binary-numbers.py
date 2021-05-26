class Solution:
    def minPartitions(self, n: str) -> int:
        sol = 0
        for s in n:
            sol=max(sol,int(s))
        return sol