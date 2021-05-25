class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        m, pq, sol, visit = [[] for i in range(len(times)+2)],[], -1, [0 for i in range(len(times)+2)]
        for u,v,w in times:
            m[u].append([v,w])
        heapq.heappush(pq,[0,k])
        while pq and n:
            w, node = heapq.heappop(pq)
            if visit[node]>0:
                continue
            visit[node]=1
            n-=1
            sol=max(sol,w)
            for ne, nw in m[node]:
                if visit[ne]>0:
                    continue
                heapq.heappush(pq,[nw+w,ne])
        return sol if n==0 else -1