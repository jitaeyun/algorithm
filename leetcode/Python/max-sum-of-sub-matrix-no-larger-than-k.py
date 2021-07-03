class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        r, c, sol = len(matrix), len(matrix[0]), -1000000
        for i in range(c):
            for j in range(i,c):
                s, curSum = [0], 0
                for l in range(r):
                    curSum += sum(matrix[l][i:j+1])
                    it = bisect.bisect_left(s, curSum - k)
                    if it < len(s):
                        sol = max(sol, curSum-s[it])
                    bisect.insort(s,curSum)
        return sol