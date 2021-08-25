class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for i in range(0,int(sqrt(c)+1)):
            x = c-i*i
            if x>=0 and x-(int(sqrt(x))**2)<1:
                return True
        return False