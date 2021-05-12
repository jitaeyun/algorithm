class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        sol, t = [1], 1
        for i in range(len(nums)-1):
            sol.append(nums[i]*sol[i])
        for i in range(len(nums)-2,-1,-1):
            t*=nums[i+1]
            sol[i]*=t
        return sol