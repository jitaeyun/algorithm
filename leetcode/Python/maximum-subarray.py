class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sol, t = nums[0], 0
        for i in range(len(nums)):
            t=max(t+nums[i],nums[i])
            sol=max(sol,t)
        return sol