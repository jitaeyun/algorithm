class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        us = set()
        def dfs(s,l,r):
            if l<r or l>n or r>n:
                return
            if l==r==n:
                us.add(s)
                return
            dfs(s+'(',l+1,r)
            dfs(s+')',l,r+1)
        dfs('',0,0)
        return list(us)
                