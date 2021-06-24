class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = 1000000007
        path = [[[0 for k in range(maxMove+1)] for j in range(n)] for i in range(m)]
        visit = [[[0 for k in range(maxMove+1)] for j in range(n)] for i in range(m)]
        dy, dx = [1,-1,0,0], [0,0,1,-1]
        path[startRow][startColumn][0]=visit[startRow][startColumn][0]=1
        def _update_path(c):
            ny, nx = 0, 0
            for y in range(m):
                for x in range(n):
                    if visit[y][x][c]>0:
                        for i in range(4):
                            ny, nx = y+dy[i], x+dx[i]
                            if ny<0 or ny>=m or nx<0 or nx>=n:
                                continue    
                            path[ny][nx][c+1]+=path[y][x][c]
                            path[ny][nx][c+1]%=MOD
                            visit[ny][nx][c+1]=1
        def _solve_path():
            sol, ny, nx = 0, 0, 0
            for y in range(m):
                for x in range(n):
                    for i in range(4):
                        ny, nx = y+dy[i], x+dx[i]
                        if ny<0 or ny>=m or nx<0 or nx>=n:
                            sol+=sum(path[y][x][0:maxMove])
                            sol%=MOD
            return sol
        for i in range(0, maxMove-1):
            _update_path(i)
        return _solve_path()
                                