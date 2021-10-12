# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        r, l, m, t = n, 1, 0, 0
        while l<=r:
            m = (l+r)//2
            t = guess(m)
            if t < 0:
                r = m-1
            elif t > 0:
                l = m+1
            else:
                break
        return m