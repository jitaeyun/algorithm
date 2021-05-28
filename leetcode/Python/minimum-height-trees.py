class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        graph, connect, sol, dq = [[] for i in range(n)], [0 for i in range(n)], [], collections.deque()
        if not edges:
            return [0]
        for f, t in edges:
            graph[f].append(t)
            graph[t].append(f)
            connect[f], connect[t] = connect[f]+1, connect[t]+1
        for i in range(n):
            if connect[i] == 1:
                dq.append(i)
        while dq:
            sol.clear()
            for i in range(len(dq)):
                t=dq.popleft() 
                connect[t]=0
                sol.append(t)
                for k in graph[t]:
                    connect[k]-=1
                    if connect[k]==1:
                        dq.append(k)
        return sol
        