class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        max_val, wy, wx = 100000000, len(mat), len(mat[0])
        for i in range(wy):
            for j in range(wx):
                if mat[i][j]==0:
                    continue
                mat[i][j] = max_val
                if i>0:
                    mat[i][j]=min(mat[i][j],mat[i-1][j]+1)
                if j>0:
                    mat[i][j]=min(mat[i][j],mat[i][j-1]+1)
        for i in range(wy-1,-1,-1):
            for j in range(wx-1,-1,-1):
                if mat[i][j]==0:
                    continue
                if i+1<wy:
                    mat[i][j]=min(mat[i][j],mat[i+1][j]+1)
                if j+1<wx:
                    mat[i][j]=min(mat[i][j],mat[i][j+1]+1)
        return mat

'''
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        y, x, ny, nx, dy, dx, = 0, 0, 0, 0, [1,-1,0,0], [0,0,1,-1]
        wy, wx, max_val = len(mat), len(mat[0]), len(mat)*len(mat[0])
        dq = collections.deque()
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j]>0:
                    mat[i][j]=max_val
                else:
                    dq.append([i,j])
        while dq:
            y, x = dq.popleft()
            for i in range(4):
                ny, nx = y+dy[i], x+dx[i]
                if ny<0 or ny>=wy or nx<0 or nx>=wx or mat[y][x]+1 >= mat[ny][nx]:
                    continue
                mat[ny][nx]=mat[y][x]+1
                dq.append([ny,nx])
        return mat
'''