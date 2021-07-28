class Solution:
    def beautifulArray(self, n: int) -> List[int]:
        sol = [i+1 for i in range(n)]
        def _devide_conquer(l, r):
            if l+1>=r:
                return
            m, sol[l:r+1] = (l+r)//2, sol[l:r+1:2] + sol[l+1:r+1:2]
            _devide_conquer(l, m)
            _devide_conquer(m+1, r)
        _devide_conquer(0, n-1)
        return sol