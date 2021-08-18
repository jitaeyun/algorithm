class Solution:
    def numDecodings(self, s: str) -> int:
        cur, prev, great_prev = 1, 1, 1
        if s[0]=='0':
            return 0
        for i in range(1,len(s)):
            cur=prev
            if s[i]=='0':
                cur= 0 if s[i-1]=='0' or s[i-1]>'2' else great_prev
            elif s[i]<='6' and s[i-1]>='1' and s[i-1]<='2':
                cur+=great_prev
            elif s[i-1]=='1':
                cur+=great_prev
            great_prev, prev = prev, cur
            if cur == 0:
                break
        return cur