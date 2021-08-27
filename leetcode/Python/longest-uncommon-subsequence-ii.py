class Solution:
    def isSubsequence(self, a, b):
        idx=0
        for i in b:
            if a[idx]==i:
                idx+=1
            if idx>=len(a):
                return True
        return False
    def findLUSlength(self, strs: List[str]) -> int:
        sol = -1
        for i in range(len(strs)):
            check=True
            for j in range(len(strs)):
                if i!=j and self.isSubsequence(strs[i],strs[j]):
                    check=False
                    break
            if check:
                sol = max(sol, len(strs[i]))
        return sol