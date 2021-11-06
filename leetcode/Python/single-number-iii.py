class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor, idx, f = 0, 1, 0
        for n in nums:
            xor ^= n
        for i in range(32):
            if xor&(idx) > 0:
                break
            idx <<= 1
        for n in nums:
            if n&idx > 0:
                f^=n
        return [f, xor^f]