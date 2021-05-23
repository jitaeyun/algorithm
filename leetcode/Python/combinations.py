class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        sol, comb = [], []
        def _combine(cur): 
            if len(comb) == k:
                sol.append(comb[:])
                return
            for i in range(cur+1,n+1):
                comb.append(i)
                _combine(i)
                comb.pop()
        _combine(0)
        return sol