class Solution:
    def numDecodings(self, s: str) -> int:
        mod = 1000000007
        c, p, n = 0,1,0
        if s[0]=='*':
            c=9
        elif s[0]!='0':
            c=1
        for i in range(1,len(s)):
            if s[i]=='*':
                n+=c*9
            elif '1'<=s[i]<='9':
                n+=c

            if s[i]=='*' and s[i-1]=='*':
                n+=p*15
            elif s[i]=='*':
                if s[i-1] == '1':
                    n+=p*9
                elif s[i-1]=='2':
                    n+=p*6
            elif s[i-1]=='*':
                if s[i]>'6':
                    n+=p
                else:
                    n+=p*2
            elif '10'<=s[i-1:i+1]<='26':
                n+=p
            n%=mod
            p, c, n = c, n, 0
        return c