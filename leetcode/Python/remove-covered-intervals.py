def compare(a, b):
    if a[0] == b[0]:
        return -1 if a[1]>b[1] else 1
    return -1 if a[0]<b[0] else 1
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        sol, mx = 0, -1
        intervals.sort(key=cmp_to_key(compare))
        for v in intervals:
            if mx<v[1]:
                sol += 1
            mx = max(mx, v[1])
        return sol