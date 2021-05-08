class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        arr=[0,1,10,100,1000,10000,100000]
        c=[str(i) for i in range(10)]
        sol, t, rs, re = 0, 0, int(sqrt(int(left))), int(sqrt(int(right)))
        for i in range(1,4):
            if rs<=i<=re:
                sol+=1
        for i in range(len(str(rs)),len(str(re))+1):
            m=i//2
            for j in range(arr[m],arr[m+1]):
                if i%2 > 0:
                    for k in c:
                        t=int(str(j)+k+str(j)[::-1])
                        if rs<=t<=re:
                            t*=t
                            if str(t) == str(t)[::-1]:
                                sol+=1
                else:
                    t=int(str(j)+str(j)[::-1])
                    if rs<=t<=re:
                        t*=t
                        if str(t) == str(t)[::-1]:
                            sol+=1
        return sol