class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        sol, cur, m = [], [], ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        if not digits:
            return sol
        def _traverse(idx: int):
            if idx==len(digits):
                sol.append("".join(cur))
                return
            for ch in m[ord(digits[idx])-50]:
                cur.append(ch)
                _traverse(idx+1)
                cur.pop()
        _traverse(0)
        return sol