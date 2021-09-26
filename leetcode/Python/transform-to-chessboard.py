class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        sz, r, c, rr, cr = len(board), 0, 0, 0, 0
        for i in range(sz):
            for j in range(sz):
                if (board[0][0]^board[i][0]^board[0][j]^board[i][j]) == 1:
                    return -1
        for i in range(sz):
            r+=board[0][i]
            c+=board[i][0]
            rr+=1 if (i&1)==board[0][i] else 0
            cr+=1 if (i&1)==board[i][0] else 0
        if not (r==sz//2 or r==(sz+1)//2) or not (c==sz//2 or c==(sz+1)//2):
            return -1
        if (sz&1)==1:
            rr = sz-rr if (rr&1)==1 else rr
            cr = sz-cr if (cr&1)==1 else cr
        else:
            rr = min(rr,sz-rr)
            cr = min(cr,sz-cr)
        return (rr+cr)//2