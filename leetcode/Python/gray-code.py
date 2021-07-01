class Solution:
    def grayCode(self, n: int) -> List[int]:
        sol, m = [0], 1
        for i in range(0,n):
            for j in range(len(sol)-1,-1,-1):
                sol.append(sol[j]+m)
            m*=2
        return sol