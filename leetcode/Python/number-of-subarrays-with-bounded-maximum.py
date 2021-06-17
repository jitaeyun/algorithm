class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        sol, f, idx, prev = 0, 0, 0, 0
        for i,v in enumerate(nums):
            if v < left:
                sol+=prev
            elif v > right:
                prev, f, idx = 0, 0, i+1
            else:
                f, prev, sol = 1, i-idx+1, sol+i-idx+1
        return sol