class Solution:
    def solve(self, board: List[List[str]]) -> None:
        dy, dx, ny ,nx, cy, cx = [1,-1,0,0], [0,0,1,-1], 0, 0, 0, 0
        visit = [[-1 for _ in range(len(board[0]))] for _ in range(len(board))]
        border_check = list()
        def traverse(y, x):
            if board[y][x]=='X' or visit[y][x]>=0:
                return
            q = collections.deque()
            g = len(border_check)
            border_check.append(0)
            q.append([y,x])
            visit[y][x]=g
            while q:
                cy, cx = q.popleft()
                if cy==0 or cy+1==len(board) or cx==0 or cx+1==len(board[0]):
                    border_check[g]=1
                for i in range(4):
                    ny, nx = cy+dy[i], cx+dx[i]
                    if ny<0 or ny>=len(board) or nx<0 or nx>=len(board[0]):
                        continue
                    elif board[ny][nx]=='X' or visit[ny][nx]>=0:
                        continue
                    visit[ny][nx]=g
                    q.append([ny,nx])
        for i in range(len(board)):
            for j in range(len(board[0])):
                traverse(i,j)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if visit[i][j]>=0 and border_check[visit[i][j]]==0:
                    board[i][j]='X'
        