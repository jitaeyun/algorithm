class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def findNum(num):
            sol = 0
            for i in range(1,m+1):
                t = min(num,n*i)//i
                sol += t
                if t == 0:
                    break;
            return sol
        l, r , mid, t, sol = 1, m*n, 0, 0, 1
        while l<=r:
            mid = (l+r)//2
            t = findNum(mid)
            if t<k:
                l=mid+1
            else:
                sol, r = mid, mid-1
        return sol