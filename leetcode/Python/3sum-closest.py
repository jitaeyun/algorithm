class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        sol, l, r, t = 100000000, 0, 0, 0
        nums.sort()
        for i in range(len(nums)-1,1,-1):
            l, r = 0, i-1
            while l<r:
                t=nums[i]+nums[l]+nums[r]
                if t<target:
                    l+=1
                elif t>target:
                    r-=1
                else:
                    return target
                if abs(sol-target) > abs(t-target):
                    sol=t
        return sol