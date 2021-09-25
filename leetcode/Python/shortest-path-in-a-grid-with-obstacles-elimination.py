class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        # 1. declare variable
        m,n,ny,nx,dx,dy, p  = len(grid), len(grid[0]), 0, 0, [1,-1,0,0], [0,0,1,-1], None
        d, r = [[-1 for _ in range(n)] for _ in range(m)], [[0 for _ in range(n)] for _ in range(m)]
        # 2. init queue for bfs
        dq = collections.deque()
        dq.append((0,0,0,0))
        d[0][0]=0
        # 3. traverse
        while dq:
            p = dq.popleft()
            if p[0]==m-1 and p[1]==n-1:
                return p[2]
            for i in range(4):
                ny, nx = p[0]+dy[i], p[1]+dx[i]
                if ny<0 or ny>=m or nx<0 or nx>=n:
                    continue
                # 3.1 first visit
                if d[ny][nx]==-1 and p[3]+grid[ny][nx]<=k:
                    d[ny][nx], r[ny][nx] = p[2]+1, p[3]+grid[ny][nx]
                    dq.append((ny,nx,p[2]+1,p[3]+grid[ny][nx]))
                # 3.2 already visit but, smaller remove count
                elif d[ny][nx]>=0 and p[3]+grid[ny][nx]<r[ny][nx]:
                    d[ny][nx], r[ny][nx] = p[2]+1, p[3]+grid[ny][nx]
                    dq.append((ny,nx,p[2]+1,p[3]+grid[ny][nx]))
        return -1