class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        def subRange(a, b):
            return str(a)+'->'+str(b) if a!=b else str(a)
        sol, prev = list(), 0
        if nums is None or len(nums) == 0:
            return sol
        prev = nums[0]
        for i in range(1, len(nums)):
            if nums[i]!=nums[i-1]+1:
                sol.append(subRange(prev, nums[i-1]))
                prev = nums[i]
        sol.append(subRange(prev, nums[-1]))
        return sol