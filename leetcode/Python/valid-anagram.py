class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m = defaultdict(int)
        if len(s)!=len(t):
            return False
        for i in s:
            m[i]+=1
        for i in t:
            m[i]-=1
            if m[i]<0:
                return False
        return True