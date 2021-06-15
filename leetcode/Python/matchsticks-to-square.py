class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        visit, s = [0 for i in range(len(matchsticks))], 0
        def dfs(idx, c, l, sz):
            if sz>=4:
                return True
            for i in range(idx,len(matchsticks)):
                if visit[i]==1 or c + matchsticks[i] > l:
                    continue
                visit[i]=1
                if c + matchsticks[i] < l:
                    if dfs(i+1, c + matchsticks[i], l, sz):
                        return True
                elif dfs(0, 0, l, sz+1):
                    return True
                visit[i]=0
            return False
        for v in matchsticks:
            s+=v
        if s%4 > 0:
            return False
        s=s//4
        return dfs(0,0,s,0)