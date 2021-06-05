class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r, p = 0, len(nums)-1, 0
        for i in range(1,len(nums)):
            if nums[i]<nums[p]:
                p+=1
                break
            p+=1
        if nums[p]<=target<=nums[-1]:
            l=p
        else:
            r=p-1
        while l<=r:
            p=(l+r)//2
            if nums[p]<target:
                l=p+1
            elif nums[p]>target:
                r=p-1
            else:
                return p
        return -1