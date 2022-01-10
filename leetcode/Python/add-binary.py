class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i, j, c, s = len(a)-1, len(b)-1, 0, 0
        sol = ''
        while i>=0 and j>=0:
            s = int(a[i])+int(b[j])+c
            c = s//2
            s%=2
            sol+='1' if s>0 else '0'
            i, j = i-1, j-1
        while i>=0:
            s = int(a[i])+c
            c = s//2
            s%=2
            sol+='1' if s>0 else '0'
            i = i-1
        while j>=0:
            s = int(b[j])+c
            c = s//2
            s%=2
            sol+='1' if s>0 else '0'
            j = j-1
        if c > 0:
            sol += '1'
        return sol[::-1]