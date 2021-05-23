class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        sol, visited, permutation = [], [0 for i in range(len(nums))], []
        def _dfs(cur):
            if cur==len(nums):
                sol.append(permutation[:])
            for i in range(len(nums)):
                if visited[i]==1:
                    continue
                visited[i]=1
                permutation.append(nums[i])
                _dfs(cur+1)
                visited[i]=0
                permutation.pop()
        _dfs(0)
        return sol