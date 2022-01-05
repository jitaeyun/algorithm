class Solution:
    def partition(self, s: str) -> List[List[str]]:
        dp, subsol, sol = [[0 for _ in range(len(s))] for _ in range(len(s))], list(), list()
        for d in range(len(s)):
            for i in range(len(s)-d):
                f = 1 if i+1 > i+d-1 else dp[i+1][i+d-1]
                dp[i][i+d] = 1 if f == 1 and s[i]==s[i+d] else 0
        def dfs(idx):
            if idx >= len(s):
                sol.append(subsol[:])
            for i in range(idx, len(s)):
                if dp[idx][i] == 1:
                    subsol.append(s[idx:i+1])
                    dfs(i+1)
                    subsol.pop()
        dfs(0)
        return sol