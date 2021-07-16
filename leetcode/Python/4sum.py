class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        s, t = set(), 0        
        nums.sort()
        for i in range(len(nums)-1, 2, -1):
            for j in range(i-1,1,-1):
                l, r = 0, j-1
                while l<r:
                    t=nums[l]+nums[r]+nums[j]+nums[i]
                    if t == target:
                        s.add((nums[l],nums[r],nums[j],nums[i]))
                        l+=1
                    elif t<target:
                        l+=1
                    else:
                        r-=1
        return list(s)