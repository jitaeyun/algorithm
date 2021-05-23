class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        sol = []
        def _combination(idx, cur, comb):
            if cur==0:
                sol.append(comb)
                return
            elif cur<0:
                return
            for i in range(idx,len(candidates)):
                _combination(i,cur-candidates[i], comb + [candidates[i]])
        _combination(0,target, [])
        return sol