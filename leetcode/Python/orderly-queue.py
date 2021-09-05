class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        sol = s
        if k==1:
            for i in range(len(s)-1):
                s = s[1:]+s[0]
                sol = min(sol,s)
        else:
            sol = ''.join(sorted(list(s)))
        return sol