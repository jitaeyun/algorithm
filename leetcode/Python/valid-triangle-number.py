class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        sol = 0
        nums.sort()
        for i in range(len(nums)-1,1,-1):
            l, r = 0, i-1
            while l<r:
                if nums[l]+nums[r]<=nums[i]:
                    l+=1
                else:
                    r, sol = r-1, sol+r-l
        return sol