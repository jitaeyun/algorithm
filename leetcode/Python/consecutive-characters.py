class Solution:
    def maxPower(self, s: str) -> int:
        sol, n = 0, 0
        for i in range(len(s)):
            if n==0 or s[i-1]==s[i]:
                n += 1
            else:
                n = 1
            sol = max(sol, n)
        return sol