class Solution:
    def isNumber(self, s: str) -> bool:
        n, dot, e = 0, 0, 0
        for i in range(len(s)):
            if '0'<=s[i]<='9':
                n+=1
            elif s[i]=='e' or s[i]=='E':
                if n > 0 and e == 0:
                    e+=1
                    n=0
                else:
                    return False
            elif s[i]=='.':
                if e == 0 and dot == 0:
                    dot+=1
                else:
                    return False
            elif s[i]=='+' or s[i]=='-':
                if i==0 or s[i-1] == 'e' or s[i-1]=='E':
                    n = 0
                else:
                    return False
            else:
                return False
        return n