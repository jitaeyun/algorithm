class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        dp = [[[-1 for _ in range(col)] for _ in range(col)] for _ in range(row)]
        def traverse(r, c1, c2):
            if r == row:
                return 0
            elif dp[r][c1][c2]>-1:
                return dp[r][c1][c2]
            mx = 0
            for i in range(max(0,c1-1), min(col, c1+2)):
                for j in range(max(0, c2-1), min(col, c2+2)):
                    if i == j:
                        continue
                    mx = max(mx, traverse(r+1, i, j))
            dp[r][c1][c2] = mx + grid[r][c1] + grid[r][c2]
            return dp[r][c1][c2]
        return traverse(0, 0, col-1)