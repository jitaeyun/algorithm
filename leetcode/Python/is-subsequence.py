class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        idx = 0
        if len(s) == 0:
            return True
        for i in range(len(t)):
            if s[idx] == t[i]:
                idx += 1
            if idx == len(s):
                break
        return True if idx == len(s) else False