class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        odd, even, sol = 1, 0, [0]*len(nums)
        for i in range(len(nums)):
            if nums[i]%2==0:
                sol[even], even = nums[i], even+2
            else:
                sol[odd], odd = nums[i], odd+2
        return sol