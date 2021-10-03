class Solution:
    def canJump(self, nums: List[int]) -> bool:
        m_idx = 0
        for i in range(len(nums)):
            if m_idx < i:
                return False
            m_idx = max(m_idx, i+nums[i])
        return True