class Solution:
    def __init__(self):
        self.sIdx = 0
        self.eIdx = 0
    def expand(self, string, s, e):
        while s>=0 and e<len(string):
            if string[s]!=string[e]:
                break
            s-=1
            e+=1
        s+=1
        e-=1
        if self.eIdx-self.sIdx+1 < e-s+1:
            self.sIdx = s
            self.eIdx = e
    def longestPalindrome(self, s: str) -> str:
        for i in range(1,len(s)):
            if s[i]==s[i-1]:
                self.expand(s,i-1,i)
            if i>1 and s[i-2]==s[i]:
                self.expand(s,i-2,i)
        return s[self.sIdx:self.eIdx+1]