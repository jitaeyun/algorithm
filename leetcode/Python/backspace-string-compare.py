class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def transString(st):
            sol = list()
            for ch in st:
                if ch == '#' and len(sol) > 0:
                    sol.pop()
                elif ch != '#':
                    sol.append(ch)
            return ''.join(sol)
        return transString(s) == transString(t)
                    