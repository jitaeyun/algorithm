class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        v, sol, val = list(), list(), 0
        for i in range(len(mat)):
            val = 0
            for j in range(len(mat[0])):
                if mat[i][j] == 1:
                    val += 1
            v.append([val, i])
        v.sort()
        for i in range(k):
            sol.append(v[i][1])
        return sol