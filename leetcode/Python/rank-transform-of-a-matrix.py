class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
        self.v = []
        self.point_groups = []
        self.group = []
    def findG(self,a):
        if self.group[a]==a:
            return a
        self.group[a] = self.findG(self.group[a])
        return self.group[a]
    def unionG(self, a, b):
        ga, gb = self.findG(a), self.findG(b)
        if ga < gb:
            self.group[gb]=ga
        elif ga > gb:
            self.group[ga]=gb
    def sortMatrix(self, matrix):
        for i in range(self.m):
            for j in range(self.n):
                self.v.append((matrix[i][j],i,j))
        self.v.sort()
    def makePointGroup(self, points):
        point_group = [[] for i in range(len(points))]
        um = dict()
        g_key = 0
        for i in range(self.m+self.n):
            self.group[i]=i
        for p in points:
            self.unionG(p[1],p[2]+self.m)
        for p in points:
            a=self.findG(p[1])
            if not a in um:
                um[a]=g_key
                g_key+=1
            point_group[um[a]].append(p)
        for pg in point_group:
            if pg:
                self.point_groups.append(pg[:])
    def rankGroups(self, matrix):
        row_rank, col_rank = [0]*(self.m), [0]*(self.n)
        for points in self.point_groups:
            r = 0
            for p in points:
                r=max(r,row_rank[p[1]]+1,col_rank[p[2]]+1)
            for p in points:
                matrix[p[1]][p[2]]=row_rank[p[1]]=col_rank[p[2]]=r
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        self.m, self.n = len(matrix), len(matrix[0])
        self.group = [i for i in range(self.m+self.n)]
        # 1. sort matrix
        self.sortMatrix(matrix)
        # 2. make group
        points = []
        for p in self.v:
            if points and points[-1][0] != p[0]:
                self.makePointGroup(points)
                points.clear()
            points.append(p[:])
        if points:
            self.makePointGroup(points)
        self.rankGroups(matrix)
        return matrix
        