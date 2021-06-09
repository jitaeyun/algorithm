class Solution:
    def hammingWeight(self, n: int) -> int:
        sol = 0
        while n > 0:
            if n&1 > 0:
                sol+=1
            n>>=1
        return sol