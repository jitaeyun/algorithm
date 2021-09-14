class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        def _isalphabet(c):
            if (c>='a' and c<='z') or (c>='A' and c<='Z'):
                return True
            return False
        sol = list(s)
        for i in range(len(sol)):
            if _isalphabet(sol[i]):
                sol[i]=0
        i, j = 0, len(s)-1
        while i<len(s) and j>=0:
            while i<len(s) and sol[i]!=0:
                i+=1
            while j>=0 and not _isalphabet(s[j]):
                j-=1
            if i<len(s) and j>=0:
                sol[i]=s[j]
                i, j = i+1, j-1
        return ''.join(sol)