class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l,r,m = 0, len(nums)-1, 0
        while l<r:
            m=(l+r)//2
            if nums[m]<nums[m+1]:
                l=m+1
            else:
                r=m
        return l