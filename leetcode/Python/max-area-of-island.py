class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        sol, ny, nx, cy, cx, dy, dx = 0, 0, 0, 0, 0, [0,0,1,-1], [1,-1,0,0] 
        def _traverse(y, x):
            num, q = 1, collections.deque()
            q.append([y,x])
            grid[y][x]=0
            while q:
                cy, cx = q.popleft()
                for i in range(4):
                    ny, nx = cy+dy[i], cx+dx[i]
                    if ny<0 or ny>=len(grid) or nx<0 or nx>=len(grid[0]):
                        continue
                    elif grid[ny][nx]>0:
                        grid[ny][nx], num = 0, num+1
                        q.append([ny,nx])
            return num

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]>0:
                    sol=max(sol,_traverse(i,j))
        return sol
            