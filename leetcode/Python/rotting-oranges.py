class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        fresh, sol, q = 0, 0, collections.deque()
        ny, nx, cy, cx, dy, dx = 0, 0, 0, 0, [1,-1,0,0], [0,0,1,-1]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    fresh+=1
                elif grid[i][j]==2:
                    q.append([i,j])
        while q:
            f = 0
            for i in range(len(q)):
                cy,cx = q.popleft()
                for j in range(4):
                    ny, nx = cy+dy[j], cx+dx[j]
                    if ny<0 or ny>=len(grid) or nx<0 or nx>=len(grid[0]):
                        continue
                    if grid[ny][nx] == 0 or grid[ny][nx]==2:
                        continue
                    grid[ny][nx]=2
                    q.append([ny, nx])
                    fresh-=1
                    if f==0:
                        f, sol = f+1, sol+1
        return sol if fresh==0 else -1
            