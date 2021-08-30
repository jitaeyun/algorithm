class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        for v in ops:
            m, n = min(m,v[0]), min(n,v[1])
        return m*n