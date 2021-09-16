class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        sol = list()
        y, x, yd, xd = 0, 0, len(matrix), len(matrix[0])
        def _traverse():
            if y<0 or y>=len(matrix) or x<0 or x>=len(matrix[0]):
                return False
            if yd<=0 or xd<=0:
                return False
            for i in range(xd):
                sol.append(matrix[y][x+i])
            for i in range(1,yd):
                sol.append(matrix[y+i][x+xd-1])
            for i in range(xd-2,-1,-1):
                if yd<=1:
                    break
                sol.append(matrix[y+yd-1][x+i])
            for i in range(yd-2,0,-1):
                if xd<=1:
                    break
                sol.append(matrix[y+i][x])
            return True
        while _traverse():
            y, x, yd, xd = y + 1, x + 1, yd - 2 , xd -2
        return sol