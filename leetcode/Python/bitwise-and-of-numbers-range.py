class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        sol, idx = 0, 1<<30
        while idx > 0:
            if idx > right:
                pass
            elif idx > left:
                break
            else:
                left, right, sol = left - idx, right - idx , sol | idx
            idx>>=1
        return sol