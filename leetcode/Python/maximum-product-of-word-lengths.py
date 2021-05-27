class Solution:
    def maxProduct(self, words: List[str]) -> int:
        trans, sol = [], 0
        for s in words:
            n = 0
            for ch in s:
                n|=(1<<(ord(ch)-ord('a')))
            trans.append(n)
        for i in range(len(words)):
            for j in range(i+1,len(words)):
                if trans[i]&trans[j]==0:
                    sol=max(sol,len(words[i])*len(words[j]))
        return sol