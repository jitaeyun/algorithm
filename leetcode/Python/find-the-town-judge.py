class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        sol, t, td = -1, [0]*(n+1), [0]*(n+1)
        for v in trust:
            td[v[1]], t[v[0]] = td[v[1]]+1, t[v[0]]+1
        for i in range(1, n+1):
            if td[i]==n-1 and t[i]==0:
                if sol == -1:
                    sol = i
                else:
                    return -1
        return sol