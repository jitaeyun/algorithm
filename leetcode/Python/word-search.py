class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        dy, dx = [1,-1,0,0], [0,0,1,-1]
        def _dfs(y, x, l):
            ny, nx, c = 0, 0, board[y][x]
            if l+1 == len(word):
                return True
            board[y][x]='0'
            for i in range(4):
                ny, nx = y+dy[i], x+dx[i]
                if ny<0 or ny>=len(board) or nx<0 or nx>=len(board[0]):
                    continue
                if board[ny][nx]==word[l+1] and _dfs(ny,nx,l+1):
                    return True
            board[y][x]=c
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==word[0] and _dfs(i,j,0):
                    return True
        return False