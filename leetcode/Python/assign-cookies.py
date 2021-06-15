class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        sol, i, j = 0, 0, 0
        s.sort(reverse=True)
        g.sort(reverse=True)
        while i<len(g) and j<len(s):
            if g[i]<=s[j]:
                sol, j = sol+1, j+1
            i+=1
        return sol