class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        zeros, ones, idx = 0, 0, 0
        for c in s:
            idx = 1 if c=='1' else 0
            ones = min(ones, zeros)+(idx^1)
            zeros = zeros+idx
        return min(ones, zeros)