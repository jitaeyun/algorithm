class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        sol=[]
        def _dfs(cur, l):
            if cur==len(nums):
                sol.append(l)
                return
            _dfs(cur+1,l)
            _dfs(cur+1,l+[nums[cur]])
        _dfs(0,[])
        return sol