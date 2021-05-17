class Solution:
    def checkPredecessor(self, s, sl):
        i,j,d=0,0,0
        while i<len(s):
            if s[i]!=sl[j]:
                if d>0:
                    return False
                i, d = i-1, d+1
            i,j = i+1, j+1
        return True
    def longestStrChain(self, words: List[str]) -> int:
        sol, acc = 1, [1 for i in range(len(words))]
        words.sort(key=len)
        for i in range(len(words)):
                for j in range(i+1,len(words)):
                    if len(words[i])+1<len(words[j]):
                        break
                    if len(words[i]) == len(words[j]):
                        continue
                    if acc[i]+1>acc[j] and self.checkPredecessor(words[i],words[j]):
                        acc[j]=acc[i]+1
                        sol=max(sol,acc[j])
        return sol