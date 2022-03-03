class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        sol, sz , p = 0, 1, 0
        if len(nums)<3:
            return sol
        p = nums[1]-nums[0]
        for i in range(1, len(nums)):
            if nums[i]-nums[i-1] == p:
                sz += 1
            else:
                sol += ((sz-2)*(sz-1))//2
                p = nums[i]-nums[i-1]
                sz = 2
        sol += ((sz-2)*(sz-1))//2
        return sol