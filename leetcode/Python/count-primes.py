class Solution:
    def countPrimes(self, n: int) -> int:
        if n<=2:
            return 0
        l, sol = [0 for i in range(n)], 1
        for i in range(3,n,2):
            if l[i]>0:
                continue
            l[i]=1
            sol+=1
            for j in range(i*3,n,i*2):
                l[j]=1
        return sol