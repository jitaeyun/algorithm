# 1. bfs solution
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        sol, mx, dq = 0, 1<<len(graph), collections.deque() 
        visit = [[0 for _ in range(mx)] for _ in range(len(graph))]
        # idx, val, visit
        for i in range(len(graph)):
            dq.append([i, 0, 1<<i])
            visit[i][1<<i] = 1
        while len(dq)>0:
            idx, val, mask = dq.popleft()
            if mask + 1 == mx:
                sol = val
                break
            for n in graph[idx]:
                n_mask = mask | (1<<n)
                if visit[n][n_mask] == 0:
                    visit[n][n_mask] = 1
                    dq.append([n, val + 1, n_mask])
        return sol

# 2. floyedwarshall + dp solution
'''
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        MAX_DIST = 100000000
        mx_dist, sol, mx = MAX_DIST, MAX_DIST, 1<<len(graph)
        dist = [[mx_dist for _ in range(len(graph))] for _ in range(len(graph))]
        dp = [[mx_dist for _ in range(mx)] for _ in range(len(graph))]
        def get_floyed():
            for i in range(len(graph)):
                for j in graph[i]:
                    dist[i][j] = dist[j][i] = 1
            for k in range(len(graph)):
                for i in range(len(graph)):
                    for j in range(len(graph)):
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
        def get_dp():
            for i in range(len(graph)):
                dp[i][1<<i]=dp[i][0]=0
            for n in range(mx):
                for i in range(len(graph)):
                    l = 1 << i
                    if l & n == 0:
                        continue
                    for j in range(len(graph)):
                        m = 1 << j
                        if i == j or m & n == 0:
                            continue
                        dp[i][n] = min(dp[i][n], dp[j][n^l] + dist[j][i])
        # 1. get floyed_warshall (minimum i to j distange)
        get_floyed()
        # 2. get dp (dp[i][j] i: last visit node, j: visit status (bit mask)) 
        get_dp()
        # 3. find minimin cost (dp[i][all_visit] (0<=i<=len(graph)))
        for i in range(len(graph)):
            sol = min(sol, dp[i][mx-1])
        return sol
'''