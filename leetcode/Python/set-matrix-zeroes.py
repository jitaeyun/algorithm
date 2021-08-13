class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n, y, x = len(matrix), len(matrix[0]), 0 ,0 
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    matrix[i][0]=matrix[0][j]=0
                    if y==0 and i==0:
                        y = 1
                    if x==0 and j==0:
                        x = 1
        for i in range(1,m):
            if matrix[i][0]==0:
                for j in range(1,n):
                    matrix[i][j]=0
        for i in range(1,n):
            if matrix[0][i]==0:
                for j in range(1, m):
                    matrix[j][i]=0
        if y>0:
            for i in range(0, n):
                matrix[0][i]=0
        if x>0:
            for i in range(0, m):
                matrix[i][0]=0
        