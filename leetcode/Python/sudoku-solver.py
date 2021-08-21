class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def availNum(y,x,v):
            sy, sx, c = (y//3)*3, (x//3)*3, str(v)
            for i in range(9):
                if board[y][i]==c or board[i][x]==c:
                    return False
            for i in range(sy,sy+3):
                for j in range(sx,sx+3):
                    if board[i][j]==c:
                        return False
            return True
        def solver():
            for i in range(9):
                for j in range(9):
                    if board[i][j]!='.':
                        continue
                    for k in range(1,10):
                        if availNum(i,j,k):
                            board[i][j]=str(k)
                            if (solver()):
                                return True
                            board[i][j]='.'
                    return False
            return True
        solver()