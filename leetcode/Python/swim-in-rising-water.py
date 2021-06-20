class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        sol, pq,dy,dx,ny,nx,cy,cx,v = 0, [], (1,-1,0,0), (0,0,1,-1), 0, 0, 0, 0, 0
        y, x = len(grid), len(grid[0])
        heapq.heappush(pq,(grid[0][0],0,0))
        grid[0][0]=-1
        while pq:
            v, cy, cx = heapq.heappop(pq)
            sol = max(sol,v)
            if cy+1==y and cx+1==x:
                break
            for i in range(4):
                ny, nx = cy+dy[i], cx+dx[i]
                if ny<0 or ny>=y or nx<0 or nx>=x or grid[ny][nx]==-1:
                    continue
                heapq.heappush(pq,(grid[ny][nx],ny,nx))
                grid[ny][nx]=-1
        return sol