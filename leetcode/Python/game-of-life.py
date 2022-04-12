class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        v = deepcopy(board)
        m, n = len(board), len(board[0])
        dy, dx = [0,0,1,-1,1,1,-1,-1], [1,-1,0,0,1,-1,1,-1]
        for i in range(m):
            for j in range(n):
                num = 0
                for k in range(8):
                    ny, nx = i+dy[k], j+dx[k]
                    if ny<0 or ny>=m or nx<0 or nx>=n:
                        continue
                    num += 1 if v[ny][nx]>0 else 0
                if num<2:
                    board[i][j] = 0
                elif num==2:
                    continue
                elif num==3:
                    board[i][j] = 1
                else:
                    board[i][j] = 0
        