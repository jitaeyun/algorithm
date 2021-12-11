class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        def gcd(num1, num2):
            if num2 == 0:
                return num1
            return gcd(num2, num1%num2)
        modulo = 1000000007
        mx, mn, lcd = max(a,b), min(a,b), (a*b)//gcd(a,b)
        l, r, m, t = 1, mx*n, 0, 0
        while l<=r:
            m = (l+r)//2
            t = (m//mx)+(m//mn)-(m//lcd)
            if t<n:
                l = m+1
            elif t>n:
                r = m-1
            else:
                break
        return (m-min(m%mn, m%mx))%modulo