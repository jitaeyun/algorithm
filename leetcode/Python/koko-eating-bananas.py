class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r, m, sol, n = 1, 1000000000, 0, 0, 0
        while l<=r:
            m, n = (l+r)//2, 0
            for p in piles:
                n += p//m + (1 if p%m > 0 else 0)
            if n<=h:
                sol, r = m, m - 1
            else:
                l = m + 1
        return sol