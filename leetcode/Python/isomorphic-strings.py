class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        v = ['\0' for _ in range(128)]
        c = [1 for _ in range(128)]
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            if v[ord(s[i])] == '\0':
                c[ord(t[i])]-=1
                if c[ord(t[i])]<0:
                    return False
                v[ord(s[i])]=t[i];
            if v[ord(s[i])]!=t[i]:
                return False
        return True