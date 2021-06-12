class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l, r, count, mx, sol = 0, 0 , collections.Counter(), 0, 0
        for i, v in enumerate(s):
            count[v]+=1
            if count[v]>count[s[mx]]:
                mx=i
            if r-l+1>count[s[mx]]+k:
                count[s[l]]-=1
                l+=1
            sol=max(sol,r-l+1)
            r+=1
        return sol
        