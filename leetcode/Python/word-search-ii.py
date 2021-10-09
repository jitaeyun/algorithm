class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def _make_path(idx):
            cur = node
            for c in words[idx]:
                cur = cur.setdefault(c, dict())
            cur['fin'] = idx + 1
        def _traverse(y, x, idx, cur):
            orig, n = board[y][x], cur.get(board[y][x])
            if idx==10 or n is None:
                return
            elif 'fin' in n:
                sol.append(words[n['fin']-1])
                del n['fin']
            board[y][x] = '0'
            for i in range(4):
                ny, nx = y + dy[i], x+ dx[i]
                if ny<0 or ny>=my or nx<0 or nx>=mx or board[ny][nx]=='0':
                    continue
                _traverse(ny, nx, idx+1, n)
            board[y][x] = orig
        # 1. init
        dy, dx, my, mx = [1,-1,0,0], [0,0,1,-1], len(board), len(board[0])
        sol, node = list(), dict()
        # 2. make path
        for i in range(len(words)):
            _make_path(i)
        # 3. traverse
        for i in range(len(board)):
            for j in range(len(board[0])):
                _traverse(i,j,0,node)
        return sol
        