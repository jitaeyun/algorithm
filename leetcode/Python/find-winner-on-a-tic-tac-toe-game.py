class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        filled, turn, decision = 0, 0, 0
        square = [[0 for _ in range(3)] for _ in range(3)]
        score = [[0 for _ in range(8)] for _ in range(2)]
        for m in moves:
            square[m[0]][m[1]]=turn
            score[turn][m[0]]+=1
            score[turn][3+m[1]]+=1
            if m[0]==m[1]:
                score[turn][6]+=1
            if m[0]+m[1]==2:
                score[turn][7]+=1
            if score[turn][m[0]]==3 or score[turn][3+m[1]]==3 or score[turn][6]==3 or score[turn][7]==3:
                decision+=1
                break
            turn, filled = turn^1, filled+1
        if decision == 1:
            return 'A' if turn==0 else 'B'
        return 'Draw' if filled==9 else 'Pending'