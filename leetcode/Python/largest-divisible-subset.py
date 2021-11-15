class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        dp, m_idx, idx = [list() for _ in range(len(nums))], 0, -1
        nums.sort()
        for i in range(len(nums)):
            idx = -1
            if i==0:
                dp[i].append(nums[i])
                continue
            for j in range(i):
                if nums[i]%dp[j][-1]==0 and (idx==-1 or len(dp[idx])<len(dp[j])):
                    idx = j
            if idx>=0:
                dp[i] = dp[idx][:]
            dp[i].append(nums[i])
            if len(dp[m_idx])<len(dp[i]):
                m_idx=i
        return dp[m_idx]