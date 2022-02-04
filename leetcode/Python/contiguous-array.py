class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        sol, um, t = 0, dict(), 0
        for i in range(len(nums)):
            t = t+1 if nums[i]==1 else t-1
            um[t] = i
        t = 0
        for i in range(len(nums)):
            sol = max(sol, um.get(t,-1)-i+1)
            t = t+1 if nums[i]==1 else t-1
        return sol