class Solution:
    def simplifyPath(self, path: str) -> str:
        v, sol, t = list(), '', ''
        path += '/'
        for ch in path:
            if ch == '/':
                if t=='..':
                    if len(v)>0:
                        v.pop()
                    t = ''
                elif t=='.':
                    t = ''
                if len(t) > 0:
                    v.append(t)
                t = ''
            else:
                t += ch
        for s in v:
            sol += '/' + s
        return sol if len(sol)>0 else '/'