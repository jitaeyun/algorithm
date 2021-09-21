class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        sol, c = 0, 0
        for n in nums:
            c = c+1 if n==1 else 0
            sol = max(sol,c)
        return sol