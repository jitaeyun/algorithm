class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        sol,m,l,r = 0, collections.defaultdict(int),0,0
        for i in range(len(s)):
            if s[i] in m:
                l=max(l,m[s[i]]+1)
            m[s[i]], sol, r = i, max(sol,r-l+1), r+1
        return sol;