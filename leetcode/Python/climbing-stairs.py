class Solution:
    def climbStairs(self, n: int) -> int:
        a,b = 1,2
        if n<3:
            return n
        for i in range(3,n+1):
            a, b = b, a+b
        return b
