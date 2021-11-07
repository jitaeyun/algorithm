class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def helper(num1, num2):
            sol, ch, a, b,c = '', '', 0, 0, 0
            i, j = len(num1)-1, len(num2)-1
            while i>=0 and j>=0:
                a=ord(num1[i])-ord('0')
                b=ord(num2[j])-ord('0')
                sol+=(str((a+b+c)%10))
                c=(a+b+c)//10
                i,j = i-1, j-1
            while i>=0:
                a=ord(num1[i])-ord('0')
                sol+=(str((a+c)%10))
                c, i =(a+c)//10, i-1
            while j>=0:
                b=ord(num2[j])-ord('0')
                sol+=(str((b+c)%10))
                c, j =(b+c)//10, j-1
            if c>0:
                sol+=('1')
            return sol[::-1]
        sol, oper, num, v = '', '', '', ['0',num1]
        if num1=='0' or num2=='0':
            return '0'
        for i in range(2,10):
            v.append(helper(v[-1],num1))
        for i in range(len(num2)-1,-1,-1):
            num = v[ord(num2[i])-ord('0')] + oper
            if len(sol)==0:
                sol = num
            else:
                sol = helper(sol, num)
            oper+=('0')
        return sol

                