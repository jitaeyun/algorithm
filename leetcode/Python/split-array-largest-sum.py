class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        def getGroup(target):
            s, g = 0, 0,
            for n in nums:
                if s + n <=target:
                    s += n
                else:
                    g, s = g + 1 , n
                if s > target:
                    return m + 1
            return g + 1 if s > 0 else g
        l, r, mid, sol = 0, 1000000000, 0, 0
        while l<=r:
            mid = (l + r)//2
            g = getGroup(mid)
            if g>m:
                l = mid + 1
            else:
                r, sol = mid - 1, mid
        return sol