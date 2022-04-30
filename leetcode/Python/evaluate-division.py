class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        sz, um, val, sol, dp  = 1, defaultdict(int), 0.0, list(), None
        # 1. make graph
        for e in equations:
            for s in e:
                if s not in um:
                    um[s], sz = sz, sz + 1
        dp = [[-1.0 for _ in range(sz)] for _ in range(sz)]
        for i in range(len(equations)):
            a=um[equations[i][0]]
            b=um[equations[i][1]]
            dp[a][b] = values[i]
            dp[b][a] = 1.0/values[i]
            dp[a][a] = dp[b][b] = 1.0
        # 2. traverse
        for k in range(sz):
            for i in range(sz):
                for j in range(sz):
                    if dp[i][k] < 0 or dp[k][j] <0:
                        continue
                    elif dp[i][j] > 0:
                        continue
                    dp[i][j] = dp[i][k]*dp[k][j]
        # 3. calc equation
        for q in queries:
            a=um[q[0]]
            b=um[q[1]]
            sol.append(dp[a][b])
        return sol