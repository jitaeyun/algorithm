class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        sol, t = 0, nums[len(nums)//2]
        for n in nums:
            sol+= t-n if t>n else n-t
        return sol