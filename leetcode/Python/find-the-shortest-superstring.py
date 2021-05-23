class Solution:
    def shortestSuperstring(self, words: List[str]) -> str:
        mx, dp = (1<<len(words))-1, [ ["" for j in range(1<<len(words))] for i in range(len(words))]
        overlaps = [[0 for j in range(len(words))] for i in range(len(words))]
        sol, t = "", ""
        def _findOverlaps():
            for i in range(len(words)):
                for j in range(len(words)):
                    if i==j:
                        continue
                    overlaps[i][j]=len(words[i])
                    for k in range(max(0,len(words[i])-len(words[j])), len(words[i])):
                        if words[i][k:] == words[j][:len(words[i])-k]:
                            overlaps[i][j]=k
                            break
        def _tsp(cur, visit):
            sol=""
            if len(dp[cur][visit]) > 0 :
                return
            elif visit==(1<<cur):
                dp[cur][visit]=words[cur]
                return
            for i in range(len(words)):
                if (visit & (1<<i)) > 0 and i!=cur:
                    _tsp(i, visit^(1<<cur))
                    t=words[cur][:overlaps[cur][i]]+dp[i][visit^(1<<cur)]
                    if len(sol) == 0 or len(sol)>len(t):
                        sol=t
            dp[cur][visit]=sol
        _findOverlaps()
        for i in range(len(words)):
            _tsp(i,mx)
            if len(sol) == 0 or len(sol)>len(dp[i][mx]):
                sol=dp[i][mx]
        return sol