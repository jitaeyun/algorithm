class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        sol, m ,n = 0, len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    sol += 4
                    if j>0 and grid[i][j-1]==1:
                        sol -= 2
                    if i>0 and grid[i-1][j]==1:
                        sol -= 2
        return sol