class Solution:
    def removeDuplicates(self, s: str) -> str:
        sol = []
        for c in s:
            if not sol or sol[-1] != c:
                sol.append(c)
                continue
            while sol and sol[-1] == c:
                sol.pop()
        return ''.join(sol)