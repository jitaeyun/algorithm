class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        sol, avail, idx = 0, 0, 0
        while avail<n:
            if idx<len(nums) and avail+1>=nums[idx]:
                avail, idx = avail+nums[idx], idx+1
            else:
                avail, sol = 2*avail+1, sol+1
        return sol