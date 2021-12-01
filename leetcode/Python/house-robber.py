class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [[0 for i in range(2)] for j in range(len(nums))]
        dp[0][1] = nums[0]
        for i in range(1,len(nums)):
            dp[i][0]=max(dp[i-1][0], dp[i-1][1])
            dp[i][1]=max(dp[i-1][0]+nums[i], dp[i-1][1])
        return max(dp[len(nums)-1][0], dp[len(nums)-1][1])



'''
class Solution:
    def rob(self, nums: List[int]) -> int:
        rob, no = nums[0], 0
        for i in range(1,len(nums)):
            no, rob = max(no, rob), max(no+nums[i], rob)
        return max(no, rob)
'''