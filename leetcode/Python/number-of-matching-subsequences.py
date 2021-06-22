class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        v, sol = [[] for i in range(26)], 0
        def _binary_search(idx):
            c, s, t = -1, -1, 0
            for i in words[idx]:
                t = ord(i)-ord('a')
                if not v[t]:
                    return False
                l,r,m = 0, len(v[t])-1, 0
                while l<=r and v[t][r]>c:
                    m=(l+r)//2
                    if v[t][m]<=c:
                        l=m+1
                    else:
                        s, r = v[t][m], m-1
                if s<=c:
                    return False
                c=s
            return True
        for i,val in enumerate(s):
            t = ord(val)-ord('a')
            v[t].append(i)
        for i in range(len(words)):
            if _binary_search(i):
                sol+=1
        return sol