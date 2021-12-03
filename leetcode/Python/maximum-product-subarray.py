class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        sol, mx, mn = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            mx, mn = mx*nums[i], mn*nums[i]
            mx, mn = max(mx,mn,nums[i]), min(mx,mn,nums[i])
            sol = max(sol,mx)
        return sol