class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color, visit = [0]*len(graph), [0]*len(graph)
        def bfs(v):
            if visit[v]>0:
                return True
            dq = collections.deque()
            dq.append(v)
            color[v] = visit[v] = 1
            while dq:
                cur = dq.popleft()
                val, nval = color[cur], 1
                if color[cur]==1:
                    nval += 1
                for ncur in graph[cur]:
                    if color[ncur]>0 and color[ncur]!=nval:
                        return False
                    elif visit[ncur]>0:
                        continue
                    dq.append(ncur)
                    color[ncur] = nval
                    visit[ncur] = 1
            return True
        for i in range(len(graph)):
            if not bfs(i):
                return False
        return True