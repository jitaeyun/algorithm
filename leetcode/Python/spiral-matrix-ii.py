class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        sol = [[0 for _ in range(n)] for _ in range(n)]
        num = [1]
        def rotate(y,x, c):
            cy, cx = y, x
            if c == 1:
                sol[cy][cx] = num[0]
                return
            for i in range(c-1):
                sol[cy][cx] = num[0]
                num[0], cx = num[0]+1, cx + 1
            for i in range(c-1):
                sol[cy][cx] = num[0]
                num[0], cy = num[0]+1, cy + 1
            for i in range(c-1):
                sol[cy][cx] = num[0]
                num[0], cx = num[0]+1, cx - 1
            for i in range(c-1):
                sol[cy][cx] = num[0]
                num[0], cy = num[0]+1, cy - 1
        y, x = 0, 0
        for c in range(n,0,-2):
            rotate(y, x, c)
            y, x = y + 1 , x + 1
        return sol
            