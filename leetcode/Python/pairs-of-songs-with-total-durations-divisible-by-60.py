class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        sol, v, i, j = 0, [0]*60, 0 , 60
        for t in time:
            v[t%60]+=1
        while i<=j:
            if i==0 or i==j:
                sol+=(v[i]*(v[i]-1))//2
            else:
                sol+=v[i]*v[j]
            i, j = i+1, j-1
        return sol