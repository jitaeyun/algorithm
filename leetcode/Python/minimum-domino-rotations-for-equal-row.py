class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        t, b, s = [0]*7, [0]*7, [0]*7
        sol, l = -1, len(tops)
        for i in range(l):
            if tops[i]==bottoms[i]:
                s[tops[i]]+=1
            t[tops[i]], b[bottoms[i]] = t[tops[i]] + 1, b[bottoms[i]] + 1
        for i in range(7):
            if t[i]+b[i]>=l+s[i]:
                if sol == -1:
                    sol = l - max(t[i], b[i])
                sol = min(sol, l - max(t[i],b[i]))
        return sol