class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        sol, remain, val = '', k, 0
        for i in range(n, 0, -1):
            val = max(1, remain - 26*(i-1))
            remain -= val
            sol += chr(val-1+ord('a'))
        return sol