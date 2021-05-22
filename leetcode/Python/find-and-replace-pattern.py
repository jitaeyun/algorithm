class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        def _replacePattern(s):
            um, sl, idx = dict(), [], 0
            for ch in s:
                if ch not in um:
                    um[ch]=str(idx)
                    idx+=1
                sl.append(um[ch])
            return ''.join(sl)
        sol, p= [], _replacePattern(pattern)
        for w in words:
            if p == _replacePattern(w):
                sol.append(w)
        return sol