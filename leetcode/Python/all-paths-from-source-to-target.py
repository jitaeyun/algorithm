class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        sol, dq = list(), collections.deque()
        dq.append([0])
        while dq:
            t = dq.popleft()
            if t[-1]+1 == len(graph):
                sol.append(t[:])
                continue
            for n in graph[t[-1]]:
                t.append(n)
                dq.append(t[:])
                t.pop()
        return sol