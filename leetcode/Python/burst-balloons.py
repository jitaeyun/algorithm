class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        dp = [[0 for _ in range(len(nums))] for _ in range(len(nums))]
        for d in range(len(nums)):
            for s in range(len(nums)-d):
                a = nums[s-1] if s>=1 else 1
                b = nums[s+d+1] if s+d+1<len(nums) else 1
                for i in range(s,s+d+1):
                    v = nums[i]*a*b
                    if i>0:
                        v += dp[s][i-1]
                    if i+1<len(nums):
                        v += dp[i+1][s+d]
                    dp[s][s+d] = max(dp[s][s+d], v)
        return dp[0][len(nums)-1]

'''
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        dp = [[-1 for _ in range(len(nums))] for _ in range(len(nums))]
        def subsolve(l,r):
            if l>r:
                return 0
            if dp[l][r]>-1:
                return dp[l][r]
            mx = 0
            a = nums[l-1] if l>0 else 1
            b = nums[r+1] if r+1<len(nums) else 1
            for i in range(l, r+1):
                mx = max(mx, nums[i]*a*b+subsolve(l, i-1)+subsolve(i+1, r))
            dp[l][r]=mx
            return mx
        return subsolve(0,len(nums)-1)
'''