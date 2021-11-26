class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r, m, sol = 0, len(nums)-1, 0, 0
        while l<=r:
            m = (l+r)//2
            if nums[m]<target:
                l, sol = m+1, m+1
            elif nums[m]>target:
                r, sol = m-1, m
            else:
                sol = m
                break
        return sol