class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        sol, j = 0, 1
        base = ord('A')
        for i in range(len(columnTitle)-1, -1, -1):
            sol += (ord(columnTitle[i])-base+1) * j
            j*=26
        return sol