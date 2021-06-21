class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        sol = []
        for i in range(1,numRows+1):
            v = []
            for j in range(i):
                if j==0 or j+1==i:
                    v.append(1)
                elif j>0:
                    v.append(sol[-1][j-1]+sol[-1][j])
            sol.append(v)
        return sol