class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        visit, sol, cur = [0]*numCourses, list(), 0
        graph = [list() for _ in range(numCourses)]
        dq = collections.deque()
        for v in prerequisites:
            graph[v[1]].append(v[0])
            visit[v[0]]+=1
        for i in range(len(visit)):
            if visit[i] == 0:
                dq.append(i)
        while dq:
            cur = dq.popleft()
            for n in graph[cur]:
                visit[n]-=1
                if visit[n] == 0:
                    dq.append(n)
            sol.append(cur)
        return sol if len(sol) == numCourses else list()