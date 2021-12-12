class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def subPartition(idx, s):
            if s==0:
                return 1
            elif idx >= len(nums) or s<0:
                return 0
            elif dp[idx][s]>=0:
                return dp[idx][s]
            dp[idx][s] = subPartition(idx+1, s-nums[idx]) | subPartition(idx+1, s)
            return dp[idx][s]
        s = 0
        for n in nums:
            s += n
        if s&1 > 0:
            return False
        dp = [[-1]*(s+1)]*len(nums)
        return subPartition(0, s//2) == 1