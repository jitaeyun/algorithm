class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        p, alphabet, um = [-1 for _ in range(len(s))], [0]*(26), dict()
        sl = list(s)
        def finds(a):
            if p[a] == -1:
                return a
            p[a] = finds(p[a])
            return p[a]
        def unions(a, b):
            a, b = finds(a), finds(b)
            if a==b:
                return
            p[a]=b
        def sorting(g):
            idx = 0
            for i in g:
                alphabet[ord(sl[i])-ord('a')] += 1
            for i in range(len(alphabet)):
                for j in range(alphabet[i]):
                    sl[g[idx]], idx = chr(ord('a')+i), idx+1
                alphabet[i] = 0
        for pair in pairs:
            unions(pair[0], pair[1])
        for i in range(len(s)):
            a = finds(i)
            if um.get(a, None) is None:
                um[a] = list()
            um[a].append(i)
        for _, g in um.items():
            sorting(g)
        return ''.join(sl)
            
            
        
            