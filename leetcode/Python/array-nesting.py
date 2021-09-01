class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        sol, visit, n, t = 0, [0]*len(nums), 0, 0
        for i in range(len(nums)):
            t, n = i, 0
            while visit[t]==0:
                visit[t], t, n = 1, nums[t], n+1
            sol=max(sol,n)
        return sol