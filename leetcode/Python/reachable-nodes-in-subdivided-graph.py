class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        MAX_VAL = 1000000000
        sol, remain, visit = 0, [[0 for _ in range(n)] for _ in range(n)], [MAX_VAL]*n
        graph = [list() for _ in range(n)]
        pq = []
        # 1. make graph
        for e in edges:
            graph[e[0]].append([e[1],e[2]])
            graph[e[1]].append([e[0],e[2]])
        # 2. traverse
        heapq.heappush(pq, (0,0))
        while pq:
            p = heapq.heappop(pq)
            if visit[p[1]]<=p[0]:
                continue
            visit[p[1]]=p[0]
            for g in graph[p[1]]:
                # 2.1 update remain
                remain[p[1]][g[0]]=max(remain[p[1]][g[0]],min(g[1],maxMoves-p[0]))
                # 2.2 update next vertex
                if p[0]+g[1]+1<=maxMoves and p[0]+g[1]+1<visit[g[0]]:
                    heapq.heappush(pq,(p[0]+g[1]+1, g[0]))
        # 3. calculation
        # 3.1 add vertex (movable)
        for i in range(n):
            sol+=1 if visit[i]<MAX_VAL else 0
        # 3.2 add edge count (movable)
        for e in edges:
            sol+=min(e[2],remain[e[0]][e[1]]+remain[e[1]][e[0]])
        return sol