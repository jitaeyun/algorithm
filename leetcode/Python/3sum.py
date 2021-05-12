class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sol = []
        nums.sort()
        l,r,t=0,0,0
        for i, n in enumerate(nums):
            if i>0 and n==nums[i-1]:
                continue
            l=i+1
            r=len(nums)-1
            while l<r:
                t=n+nums[l]+nums[r]
                if t>0:
                    r-=1
                elif t<0:
                    l+=1
                else:
                    sol.append([n,nums[l],nums[r]])
                    while l<r and nums[l]==nums[l+1]:
                        l+=1
                    while l<r and nums[r]==nums[r-1]:
                        r-=1
                    l+=1
                    r-=1
        return sol