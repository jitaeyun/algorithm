class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        sol, deleteIdx, plusIdx, acc, j = '', list(), list(), 0, 0
        for i in range(len(s)):
            if s[i] == '(':
                acc += 1
                plusIdx.append(i)
            elif s[i] == ')':
                if acc <= 0:
                    deleteIdx.append(i)
                else:
                    acc -= 1
        for i in range(len(s)):
            if j < len(deleteIdx) and deleteIdx[j] == i:
                j += 1
            elif j>= len(deleteIdx) and acc > 0 and plusIdx[-acc]==i:
                acc -= 1
            else:
                sol += s[i]
        return sol