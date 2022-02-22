class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        v, s = list(), 0
        for ch in num:
            while len(v)>0 and k>0 and v[-1]>ch:
                v.pop(); k-=1
            v.append(ch)
        while k>0:
            k-=1 ; v.pop()
        while s < len(v):
            if v[s] != '0':
                break
            s += 1
        return ''.join(v[s:]) if s < len(v) else '0'