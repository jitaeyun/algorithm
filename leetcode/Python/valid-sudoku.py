class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValidRow(idx):
            s = set()
            for c in board[idx]:
                if c == '.':
                    continue
                if c in s:
                    return False
                s.add(c)
            return True
        def isValidCol(idx): 
            s = set()
            for i in range(len(board)):
                if board[i][idx]=='.':
                    continue
                if board[i][idx] in s:
                    return False
                s.add(board[i][idx])
            return True
        def isValidCube(idx):
            s = set()
            r, c = (idx//3)*3, (idx%3)*3
            for i in range(r,r+3):
                for j in range(c,c+3):
                    if board[i][j]=='.':
                        continue
                    if board[i][j] in s:
                        return False
                    s.add(board[i][j])
            return True
        for i in range(9):
            check = isValidRow(i) and isValidCol(i) and isValidCube(i)
            if not check:
                return False
        return True