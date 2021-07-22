class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        mn, mx, t = [0]*len(nums), 0, nums[-1]
        for i in range(len(nums)-1,-1,-1):
            t=min(t,nums[i])
            mn[i] = t
        for i in range(len(nums)-1):
            mx=max(mx,nums[i])
            if mx<=mn[i+1]:
                return i+1
        return len(nums)
        