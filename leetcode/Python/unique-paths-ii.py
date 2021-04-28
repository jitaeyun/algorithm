class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        h, w = len(obstacleGrid), len(obstacleGrid[0])
        cur = prev = [0 for i in range(w)]
        if obstacleGrid[0][0] == 0:
            cur[0] = 1
        for i in range(h):
            for j in range(w):
                if obstacleGrid[i][j]:
                    continue
                if i:
                    cur[j]+=prev[j]
                if j:
                    cur[j]+=cur[j-1]
            prev = cur
            cur = [0 for j in range(w)]
        return prev[w-1]
