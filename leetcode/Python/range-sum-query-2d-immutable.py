class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.m = []
        t=0
        for i, m in enumerate(matrix):
            l,pSum = [], 0
            for j, v in enumerate(m):
                pSum+=v
                t=pSum
                if i > 0:
                    t+=self.m[i-1][j]
                l.append(t)
            self.m.append(l)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sol=self.m[row2][col2]
        if row1:
            sol-=self.m[row1-1][col2]
        if col1:
            sol-=self.m[row2][col1-1]
        if row1 and col1:
            sol+=self.m[row1-1][col1-1]
        return sol


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)