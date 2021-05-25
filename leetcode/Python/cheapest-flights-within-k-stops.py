class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        m, dp, sol, pq = [[] for i in range(n)], [-1 for i in range(n)], -1, []
        for f, t ,p in flights:
            m[f].append([t,p])
        heapq.heappush(pq,(0,0,src))
        while pq:
            c, w, node = heapq.heappop(pq)
            if c>k+1:
                break
            elif dp[node]==-1 or dp[node]>w:
                dp[node]=w
                if node==dst:
                    sol=w
                for ne, nw in m[node]:
                    heapq.heappush(pq,(c+1,w+nw,ne))
        return sol