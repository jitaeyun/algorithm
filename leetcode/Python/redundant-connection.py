class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        visit, idx = [0 for _ in range(len(edges)+1)], 0
        def _union(a, b):
            va, vb = _find(a), _find(b)
            if va!=vb:
                visit[va]=vb
            return va!=vb
        def _find(n):
            if visit[n]==0:
                return n
            visit[n]=_find(visit[n])
            return visit[n]
        for i, v in enumerate(edges):
            if not _union(v[0],v[1]):
                idx=i
        return edges[idx]