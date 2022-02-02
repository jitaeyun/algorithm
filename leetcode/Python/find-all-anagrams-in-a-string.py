class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        sol, v = list(), [0]*26
        l, r, base = 0, 0, ord('a')
        for ch in p:
            v[ord(ch)-base] += 1
        while r < len(s):
            while l<r and v[ord(s[r])-base] == 0:
                v[ord(s[l])-base]+=1; l+=1
            if v[ord(s[r])-base] == 0:
                l, r = l+1, r+1
            else:
                v[ord(s[r])-base]-=1 ; r+=1
            if r-l == len(p):
                v[ord(s[l])-base]+=1; sol.append(l)
                l+=1
        return sol