class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        sol, tot, dp = 0, 0, [dict() for _ in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i):
                diff=nums[i]-nums[j]
                tot = dp[j].get(diff,0)
                dp[i][diff], sol = dp[i].get(diff,0)+tot+1, sol + tot
        return sol