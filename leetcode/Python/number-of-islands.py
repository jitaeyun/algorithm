class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        sol, q = 0, collections.deque()
        ny, nx, cy, cx, dy, dx = 0, 0, 0, 0, (1,-1,0,0) , (0,0,1,-1)
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=='0':
                    continue
                q.append((i,j))
                grid[i][j]='0'
                sol+=1
                while len(q)>0:
                    cy, cx = q.popleft()
                    for k in range(4):
                        ny=cy+dy[k]
                        nx=cx+dx[k]
                        if ny<0 or nx<0 or ny>=len(grid) or nx>=len(grid[i]):
                            continue
                        elif grid[ny][nx]=='0':
                            continue
                        q.append((ny,nx))
                        grid[ny][nx]='0'
        return sol