class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        v = [[0 for _ in range(i+1)] for i in range(query_row+2)]
        v[0][0] = poured
        for i in range(query_row+1):
            avail = 0
            for j in range(i+1):
                if v[i][j]>=1:
                    v[i][j]-=1
                    v[i+1][j] += v[i][j]/2
                    v[i+1][j+1] += v[i][j]/2
                    v[i][j] = 1
                    avail += 1
            if avail == 0:
                break
        return v[query_row][query_glass]