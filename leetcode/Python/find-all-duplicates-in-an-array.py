class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        sol = list()
        for n in nums:
            n = n if n>0 else -n
            if nums[n-1]<0:
                sol.append(n)
            else:
                nums[n-1]=-nums[n-1]
        return sol