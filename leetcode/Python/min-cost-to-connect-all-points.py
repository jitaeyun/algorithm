class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        graph, pq, visited, visit = [list() for _ in range(len(points))], list(), 0, [0]*(len(points))
        sol, idx = 0, 0
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                dist = int(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]))
                graph[i].append([dist, j])
                graph[j].append([dist, i])
        visited, visit[0] = visited+1, 1
        for g in graph[0]:
            heapq.heappush(pq, g)
        while pq and visited<len(points):
            dist, cur = heapq.heappop(pq)
            if visit[cur]>0:
                continue
            sol, visit[cur], visited = sol + dist , 1, visited+1
            for g in graph[cur]:
                if visit[g[1]]==0:
                    heapq.heappush(pq, g)
        return sol