class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        sol,s, e = 0, 0, 0
        if len(matrix) == 0:
            return sol
        m = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        dp = [[0 for _ in range(len(matrix))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])-1, -1, -1):
                if j+1 < len(matrix[0]):
                    m[i][j] = m[i][j+1]
                if matrix[i][j]=='1':
                    m[i][j]+=1
                else:
                    m[i][j]=0
        for j in range(len(matrix[0])):
            s=e=0
            while s<len(matrix):
                while s<len(matrix) and m[s][j]==0:
                    s+=1
                e=s
                while e<len(matrix):
                    if m[e][j]==0:
                        break
                    e+=1
                e-=1
                for d in range(0, e-s+1):
                    for i in range(s, e-d+1):
                        if d==0:
                            dp[i][i+d]=m[i][j]
                        else:
                            dp[i][i+d]=min(dp[i][i+d-1], dp[i+d][i+d])
                        sol = max(sol, dp[i][i+d]*(d+1))
                s=e+1
        return sol