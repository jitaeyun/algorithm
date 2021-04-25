class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        sz = len(matrix)
        for i in range(sz):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(sz):
            for j in range(sz//2):
                matrix[i][j], matrix[i][sz-1-j] = matrix[i][sz-1-j], matrix[i][j]
        