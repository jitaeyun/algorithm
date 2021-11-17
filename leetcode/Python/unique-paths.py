class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        v = [1]*n
        for i in range(1, m):
            for j in range(1, n):
                v[j]+=v[j-1]
        return v[-1]