class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def rowSearch():
            l, r, m = 0, len(matrix)-1, 0
            sol = l
            while l<=r:
                m = (l+r)//2
                if matrix[m][0]>target:
                    r = m - 1
                else:
                    sol, l = m, m+1
            return sol
        def colSearch(row):
            l, r, m = 0, len(row)-1, 0
            while l<=r:
                m = (l+r)//2
                if row[m] > target:
                    r = m - 1
                elif row[m] < target:
                    l = m + 1
                else:
                    return True
            return False
        return colSearch(matrix[rowSearch()])