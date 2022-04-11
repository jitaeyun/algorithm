class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        v = deepcopy(grid)
        m, n = len(grid), len(grid[0])
        ny, nx = 0, 0
        for i in range(m):
            for j in range(n):
                nx = j + k
                ny = i + nx//n
                ny, nx = ny%m, nx%n
                v[ny][nx]=grid[i][j]
        return v