class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        sol, l, r = 0, points[0][0], points[0][1]
        for p in points:
            l, r = max(l, p[0]), min(r, p[1])
            if l > r:
                sol, l, r = sol + 1, p[0], p[1]
        return sol + 1