class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def _conversion(s):
            bit, t = 0, 0
            for c in s:
                t = 1<<(ord(c)-ord('a'))
                if (bit&t) != 0:
                    return
                bit|=t
            bits.append([bit, len(s)])
        sol, bits, dp = 0, [], []
        for s in arr:
            _conversion(s)
        for b in bits:
            for d in dp:
                if (b[0]&d[0]) == 0:
                    dp.append([b[0]|d[0], b[1]+d[1]])
                    sol=max(sol,dp[-1][1])
            dp.append([b[0],b[1]])
            sol=max(sol,dp[-1][1])
        return sol
        