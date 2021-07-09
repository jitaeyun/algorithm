class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sol, l, r, m, t, v = 0, 0, 0, 0, 0, []
        for i in range(len(nums)):
            if not v or v[-1]<nums[i]:
                v.append(nums[i])
                sol=len(v)
                continue
            l, r = 0, len(v)-1
            while l<=r:
                m=(l+r)//2
                if v[m]<nums[i]:
                    l=m+1
                else:
                    r, t = m-1, m
            v[t]=nums[i]
        return sol