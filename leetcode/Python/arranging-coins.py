class Solution:
    def arrangeCoins(self, n: int) -> int:
        l, r, m, t, sol = 0, 2*(int(sqrt(n+1))+1), 0, 0, 0
        while l<=r:
            m = (l+r)//2
            t = (m*(m+1))//2
            if n<t:
                r = m-1
            else:
                l, sol = m + 1, m
        return sol