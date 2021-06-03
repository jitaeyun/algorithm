class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        mod = 1000000007
        hd, vd, hp, vp = 0, 0, 0, 0
        horizontalCuts.sort()
        horizontalCuts.append(h)
        verticalCuts.sort()
        verticalCuts.append(w)
        for i in horizontalCuts:
            hd, hp = max(hd,i-hp), i
        for i in verticalCuts:
            vd, vp = max(vd,i-vp), i
        return hd*vd%mod