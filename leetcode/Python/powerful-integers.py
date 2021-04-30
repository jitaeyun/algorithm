class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        sol,m,sz,n = [], [0 for i in range(bound+1)],0,1
        while n+1<=bound:
            sol.append(n+1)
            m[n+1]=1
            n*=x
            if x==1 :
                break
        n=1
        sz=len(sol)
        while n<=bound:
            for i in range(sz):
                t=sol[i]+n-1
                if t<=bound:
                    if m[t] == 0:
                        m[t] = 1
                        sol.append(t)
                elif i == 0:
                    return sol
                else:
                    break
            if y==1:
                break
            n*=y
        return sol