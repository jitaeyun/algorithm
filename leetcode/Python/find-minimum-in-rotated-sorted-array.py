class Solution:
    def findMin(self, nums: List[int]) -> int:
        sol, l, r, m = nums[0], 0, len(nums)-1, 0
        while l<=r:
            m = (l+r)//2
            sol = min(sol, nums[m])
            if nums[m]>nums[r]:
                l=m+1
            else:
                r=m-1
        return sol