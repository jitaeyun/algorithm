class Solution:
    def __init__(self):
        self.sol = []

    def subMake(self, s):
        if len(s) == 1:
            return [s]
        elif s[0]==s[-1]=='0':
            return []
        elif s[0]=='0':
            return [s[0:1]+'.'+s[1:]]
        elif s[-1]=='0':
            return [s]
        sol = [s]
        for i in range(1,len(s)):
            sol.append(s[:i]+'.'+s[i:])
        return sol
            
    def makeCoordinate(self, s, d):
        a, b = s[0:d], s[d:]
        l = self.subMake(a)
        r = self.subMake(b)
        for i in l:
            for j in r:
                self.sol.append('('+i+', '+j+')')
                
    def ambiguousCoordinates(self, s: str) -> List[str]:
        s=s[1:-1]
        for i in range(1,len(s)):
            self.makeCoordinate(s,i)
        return self.sol