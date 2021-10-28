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
'''
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sol, v , us, s, t = list(), list(), set(), None, 0
        if not nums:
            return sol
        nums.sort()
        v.append(nums[0])
        same=1
        for i in range(1, len(nums)):
            if nums[i]==nums[i-1]:
                same+=1
            else: 
                same = 1
            if same<4:
                v.append(nums[i])
        for i in range(len(v)):
            j, k = i+1, len(v)-1
            while j<k:
                t=v[i]+v[j]+v[k]
                if t == 0:
                    s = '{}.{}.{}'.format(v[i],v[j],v[k])
                    if s not in us:
                        us.add(s)
                        sol.append([v[i], v[j], v[k]])
                    j+=1
                elif t>0:
                    k-=1
                else:
                    j+=1
        return sol
'''