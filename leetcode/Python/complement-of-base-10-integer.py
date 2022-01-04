class Solution:
    def bitwiseComplement(self, n: int) -> int:
        tot = 1<<30
        if n == 0:
            return 1
        while tot>0:
            if tot & n > 0:
                break
            tot>>=1
        tot = (tot<<1) - 1
        return tot^n