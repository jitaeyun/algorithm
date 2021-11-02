class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        sy,sx,ey,ex,dy,dx, c = 0, 0, 0, 0, [1,-1,0,0], [0,0,1,-1], 0
        visit = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        def traverse(y,x,cnt):
            if cnt==0:
                return 1 if y==sy and x==sx else 0
            visit[y][x]=1
            res, ny , nx = 0,0,0
            for i in range(4):
                ny, nx = y+dy[i], x+dx[i]
                if ny<0 or ny>=len(grid) or nx<0 or nx>=len(grid[0]) or grid[ny][nx]==-1 or visit[ny][nx]==1:
                    continue
                res += traverse(ny,nx,cnt-1)
            visit[y][x]=0
            return res
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]!=-1:
                    c+=1
                if grid[i][j]==1:
                    sy, sx = i, j
                elif grid[i][j]==2:
                    ey, ex = i, j
        return traverse(ey,ex,c-1)