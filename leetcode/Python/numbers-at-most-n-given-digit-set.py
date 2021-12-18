class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        num = str(n)
        sol = len(num)-1
        digit, mn, mul = [0]*10, [0]*10, [1]*10
        for s in digits:
            digit[int(s)]+=1
        for i in range(1,10):
            mn[i]=mn[i-1]+digit[i]
            if i==1:
                mul[i]=len(digits)
            else:
                mul[i]=mul[i-1]*(len(digits))
        if len(digits) > 1:
            sol = (len(digits)*(mul[len(num)-1]-1))//(len(digits)-1)
        for i in range(len(num)):
            idx = ord(num[i])-ord('0')
            sol += (mn[idx]-digit[idx])*mul[len(num)-1-i]
            if digit[idx]==0:
                break
            elif i+1 == len(num):
                sol+=1
        return sol