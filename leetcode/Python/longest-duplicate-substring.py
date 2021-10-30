class Solution:
    def longestDupSubstring(self, s: str) -> str:
        sol, t, mod, power = '', '', 10000007, list()
        def _rabin_karp(sz):
            if sz==0:
                return ''
            um, hash_func, p =dict(), 0, 1
            init_idx = ord('a')
            subs = ''
            for i in range(sz):
                hash_func=(hash_func*26+ord(s[i])-init_idx)%mod
                if i>0:
                    p=(p*26)%mod
            um[hash_func]=[0]
            for i in range(sz,len(s)):
                hash_func=(hash_func-(ord(s[i-sz])-init_idx)*p+26*mod)%mod
                hash_func=(hash_func*26+ord(s[i])-init_idx)%mod
                l = um.get(hash_func,None)
                if l is None:
                    um[hash_func]=[i-sz+1]
                else:
                    subs=s[i-sz+1:i+1]
                    for idx in l:
                        if subs==s[idx:idx+sz]:
                            return subs
                    l.append(i-sz+1)
            return ''
        l,r,m = 1, len(s)-1, 0
        while l<=r:
            m = (l+r)//2
            t = _rabin_karp(m)
            if len(t) == 0:
                r=m-1
            else:
                sol, l = t, m+1
        return sol

'''
1) 처음써본 라빈카프 알고리즘 (기법자체는 어렵지 않았으나 해시를 잘 이해해야함)
2) 이진탐색의 접근법을 잘 떠올려야함
3) 종합: 어려웠고, 다시 풀만할 가치가 있는 문제
'''