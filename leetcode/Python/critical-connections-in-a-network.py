class Solution:
    def __init__ (self):
        self.sol, self.v, self.visited, self.r = [], [], [], []
    def dfs(self, prev, cur, t):
        self.visited[cur]=1
        self.r[cur]=t
        for nextNode in self.v[cur]:
            if prev == nextNode:
                continue
            elif self.visited[nextNode] == 0:
                self.dfs(cur, nextNode, t+1)
            self.r[cur] = min(self.r[cur], self.r[nextNode])
            if self.r[nextNode] > t:
                self.sol.append([cur, nextNode])
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        for i in range(n):
            self.v.append([])
            self.r.append(0)
            self.visited.append(0)
        for node in connections:
            self.v[node[0]].append(node[1])
            self.v[node[1]].append(node[0])
        self.dfs(-1,0,1)
        return self.sol
        