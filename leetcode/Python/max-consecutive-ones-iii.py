class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        sol, t, l, r = 0, 0, 0, 0
        while r<len(nums):
            if nums[r]==1:
                t, r = t+1, r+1
            elif k>0:
                k,t,nums[r],r=k-1,t+1,-1,r+1
            elif nums[l]==0:
                l+=1
            elif nums[l]==1:
                l, t = l+1, t-1
            else:
                l,t,k = l+1, t-1, k+1
            if l>=r:
                r+=1
            sol=max(sol,t)
        return sol