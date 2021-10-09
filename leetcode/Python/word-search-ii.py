class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def _traverse(y, x, idx, cur):
            if idx==10:
                return
            orig, n = board[y][x], cur
            board[y][x] = '0'
            if cur.get(orig) is None:
                n = cur[orig] = dict()
            else:
                n = cur[orig]
            for i in range(4):
                ny, nx = y + dy[i], x+ dx[i]
                if ny<0 or ny>=my or nx<0 or nx>=mx or board[ny][nx]=='0':
                    continue
                _traverse(ny, nx, idx+1, n)
            board[y][x] = orig
        def _search_prefix(word):
            cur = um
            for c in word:
                if (cur := cur.get(c)) is None:
                    return False
            return True
                    
        # 1. init
        dy, dx, my, mx = [1,-1,0,0], [0,0,1,-1], len(board), len(board[0])
        sol, d, um = list(), set(), dict()
        for word in words:
            d.add(word[0])
        # 2. traverse
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] in d:
                    _traverse(i,j,0,um)
        # 3. search_prefix
        for word in words:
            if _search_prefix(word):
                sol.append(word)
        return sol
        