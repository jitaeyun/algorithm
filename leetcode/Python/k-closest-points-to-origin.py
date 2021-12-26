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


'''
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        sol, hq = list(), list()
        for i in range(len(points)):
            heapq.heappush(hq, (points[i][0]*points[i][0]+points[i][1]*points[i][1], i))
        for i in range(k):
            t = heapq.heappop(hq)
            sol.append(points[t[1]])
        return sol
'''