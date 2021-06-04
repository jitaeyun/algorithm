class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        sol, v, i = [], [], 0
        for y,x in points:
            v.append([y*y+x*x, i])
            i+=1
        v.sort()
        for i in range(k):
            sol.append(points[v[i][1]])
        return sol