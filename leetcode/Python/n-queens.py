class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        sol, m, f, d = [], [['.' for i in range(n)] for j in range(n)], 0, 0
        def _traverseNqueens(cur):
            if cur==n:
                sol.append([''.join(s) for s in m])
                return
            for i in range(n):
                f=0
                for j in range(cur):
                    d=cur-j
                    if m[j][i] == 'Q' or (i>=d and m[j][i-d] == 'Q') or (i+d<n and m[j][i+d] == 'Q'):
                        f=1
                        break
                if f==0:
                    m[cur][i]='Q'
                    _traverseNqueens(cur+1)
                    m[cur][i]='.'
        _traverseNqueens(0)
        return sol