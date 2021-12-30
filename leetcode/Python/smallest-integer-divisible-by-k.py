class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        num = 0
        for idx in range(1, k+1):
            num = (num*10+1)%k
            if num == 0:
                return idx
        return -1