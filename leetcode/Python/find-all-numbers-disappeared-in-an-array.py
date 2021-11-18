class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        sol, t = list(), 0
        for i in range(len(nums)):
            t = abs(nums[i])-1
            if nums[t] > 0:
                nums[t] *= -1
        for i in range(len(nums)):
            if nums[i]>0:
                sol.append(i+1)
        return sol
        