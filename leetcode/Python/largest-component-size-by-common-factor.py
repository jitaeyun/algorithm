class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        def find(g):
            if group[g] == 0:
                return g
            group[g]=find(group[g])
            return group[g]
        def unions(a, b):
            a, b = find(a), find(b)
            if a<b:
                group[b]=a
            elif a>b:
                group[a]=b
            return min(a,b)
        sol, g = 0, 0
        group, v, aggr, is_prime = [0], [-1]*(100001), [0], [1]*(100001)
        is_prime[0]=is_prime[1]=0
        for n in nums:
            v[n]=0
        for i in range(2,100001):
            if is_prime[i]==0:
                continue
            g = len(group)
            group.append(0)
            aggr.append(0)
            for j in range(i, 100001, i):
                if i<j:
                    is_prime[j] = 0
                if v[j] == 0:
                    v[j] = g
                elif v[j]>0:
                    v[j] = unions(v[j], g)
        for n in nums:
            g=find(v[n])
            aggr[g]+=1
            sol=max(sol,aggr[g])
        return sol