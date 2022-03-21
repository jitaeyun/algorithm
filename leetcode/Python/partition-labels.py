class Solution:
    def subSolve(self, idx, v, s):
        l, r, ed = idx, idx, v[ord(s[idx])-ord('a')], 
        while r<ed:
            ed = max(ed, v[ord(s[r])-ord('a')])
            r += 1
        return ed-l+1
            
        
    def partitionLabels(self, s: str) -> List[int]:
        v, sol, idx  = [0]*26, list(), 0
        for i, ch in enumerate(s):
            v[ord(ch)-ord('a')] = i
        while idx < len(s):
            l = self.subSolve(idx, v, s)
            sol.append(l)
            idx += l
        return sol