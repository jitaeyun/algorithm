class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        sol, mod, um = 0, 1000000007, dict()
        def combination(a, b, c):
            i, j, k = um[a], um[b], um[c]
            if a==b==c:
                return ((i*(i-1)*(i-2))//6)%mod if i>=3 else 0
            elif a==b:
                return (((i*(i-1))//2)*k)%mod if i>=2 else 0
            elif b==c:
                return (((j*(j-1))//2)*i)%mod if j>=2 else 0
            elif a==c:
                return (((i*(i-1))//2)*j)%mod if i>=2 else 0
            return (i*j*k)%mod
        for n in arr:
            num = um.get(n, 0)
            um[n] = num + 1
        for i in range(target+1):
            if i not in um:
                continue
            for j in range(i,target+1):
                if j not in um:
                    continue
                k = target-i-j
                if k>=j and k in um:
                    sol += combination(i,j,k)
                    sol%=mod
        return sol