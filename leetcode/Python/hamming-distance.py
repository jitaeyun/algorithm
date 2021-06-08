class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        z, sol = x^y, 0
        while z>0:
            if z&1 > 0:
                sol+=1
            z>>=1
        return sol