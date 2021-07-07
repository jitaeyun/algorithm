class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        sol, sz = 0, len(matrix)
        l, r, m, c , idx = matrix[0][0], matrix[sz-1][sz-1], 0, 0, sz-1
        while l<=r:
            m = (l+r)//2
            c, idx = 0, sz-1
            for i in range(sz):
                while idx>=0 and matrix[i][idx]>m:
                    idx-=1
                c+=idx+1
            if k<=c:
                sol, r = m, m-1
            else:
                l=m+1
        return sol