class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        r, c = len(heights), len(heights[0])
        dp, pq = [[-1 for _ in range(c)] for _ in range(r)], list()
        dy, dx, cy, cx, ny, nx, val , nval = [1,-1,0,0], [0,0,1,-1], 0, 0, 0, 0, 0, 0
        dp[0][0]=0; heapq.heappush(pq, (0,0,0))
        while pq:
            val, cy, cx = heapq.heappop(pq)
            if val > dp[cy][cx]:
                continue
            for i in range(4):
                ny, nx = cy+dy[i], cx+dx[i]
                if ny<0 or ny>=r or nx<0 or nx>=c:
                    continue
                nval = max(val, abs(heights[cy][cx]-heights[ny][nx]))
                if dp[ny][nx] == -1 or nval<dp[ny][nx]:
                    heapq.heappush(pq, (nval,ny,nx)); dp[ny][nx] = nval
        return dp[-1][-1]