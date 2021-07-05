class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        sol, v, sz = [], [], len(mat)*len(mat[0])
        if sz!=r*c:
            return mat
        for i in range(sz):
            y, x = i//len(mat[0]), i%len(mat[0])
            v.append(mat[y][x])
            if len(v) == c:
                sol.append(v[:])
                v.clear()
        return sol