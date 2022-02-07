class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        v = defaultdict(int)
        for ch in s:
            v[ch]+=1
        for ch in t:
            v[ch]-=1
            if v[ch]<0:
                return ch
        return t[-1]