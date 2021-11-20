class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r, m = 0, len(nums)-1, 0
        while l<r:
            m = (l+r)//2
            if nums[m]==nums[m-1]:
                m+=1
            if (r-m+1)%2==1:
                l=m
            else:
                r=m-1
        return nums[l]