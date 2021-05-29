class Solution:
    def totalNQueens(self, n: int) -> int:
        m = [[0 for i in range(n)] for j in range(n)]
        def traverse(c):
            if c==n:
                return 1
            sol=0
            for i in range(n):
                j=0
                while j<c:
                    if m[i][j]>0 or (i+j>=c and m[i+j-c][j]>0) or (i+c<n+j and m[i-j+c][j]>0):
                        break
                    j+=1
                if j==c:
                    m[i][c]=1;
                    sol+=traverse(c+1)
                    m[i][c]=0;
            return sol
        return traverse(0)