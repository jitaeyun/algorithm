class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        s, t = 0, 0
        for n in nums:
            t += n
            s = min(s, t)
        return 1-s if s<0 else 1