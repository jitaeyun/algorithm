class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        sol, v = -1, [0]*(len(nums)+1)
        for n in nums:
            v[n] += 1
            if v[n] == 2:
                sol = n
                break
        return sol