class Solution:
    def findComplement(self, num: int) -> int:
        sol, idx = 0, 1<<30
        while num&idx == 0:
            idx >>= 1
        while idx>0:
            if num&idx == 0:
                sol |= idx
            idx >>= 1
        return sol