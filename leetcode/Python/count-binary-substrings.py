class Solution:
    def countBinarySubstrings(self, s: str):
        n = [0,0]
        sol, state, cur = 0, 0, 0
        for i in s:
            cur = int(i)
            if state != cur:
                n[cur] = 0
            state = cur
            n[cur]+=1
            if n[cur^1]>=n[cur] and n[cur^1]:
                sol+=1
        return sol