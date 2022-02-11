class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        v, l, idx, base = [0]*26, 0, 0, ord('a')
        for ch in s1:
            v[ord(ch)-base]+=1
        for r in range(len(s2)):
            idx = ord(s2[r])-base
            while v[idx] == 0 and l<r:
                v[ord(s2[l])-base] += 1
                l += 1
            if v[idx] > 0:
                v[idx] -= 1
            else:
                l += 1
            if r-l+1 == len(s1):
                return True
        return False
        