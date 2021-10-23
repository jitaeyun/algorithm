class Solution:
    def findMin(self, nums: List[int]) -> int:
        # erase duplicate
        # binary search
        l, r, m , sol = 0, len(nums)-1, 0, nums[0]
        while l<=r:
            while l<r and (nums[l]==nums[l+1] or nums[l]==nums[r]):
                l+=1
            while l<r and nums[r]==nums[r-1]:
                r-=1
            m = (l+r)//2
            sol = min(sol, nums[m])
            if nums[m]>nums[r]:
                l = m + 1
            else:
                r = m - 1
        return sol