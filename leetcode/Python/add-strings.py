class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        m, p_n1, p_n2, carry = max(len(num1),len(num2)), len(num1)-1, len(num2)-1, 0
        sol = ['1']*(m+1)
        while p_n1>=0 and p_n2>=0:
            n=int(num1[p_n1])+int(num2[p_n2])+carry
            carry=n//10
            sol[m]= str(n%10)
            m, p_n1, p_n2 = m-1, p_n1-1, p_n2-1
        while p_n1>=0:
            n=int(num1[p_n1])+carry
            carry=n//10
            sol[m]= str(n%10)
            m, p_n1 = m-1, p_n1-1
        while p_n2>=0:
            n=int(num2[p_n2])+carry
            carry=n//10
            sol[m]= str(n%10)
            m, p_n2 = m-1, p_n2-1
        if carry==0:
            return ''.join(sol[1:])
        return ''.join(sol)