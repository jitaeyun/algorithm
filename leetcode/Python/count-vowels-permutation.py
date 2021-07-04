class Solution:
    def countVowelPermutation(self, n: int) -> int:
        MOD, sol = 1000000007, 0
        prev, cur = [1]*5, [1]*5
        for i in range(2,n+1):
            cur[0]=(prev[1]+prev[2]+prev[4])%MOD
            cur[1]=(prev[0]+prev[2])%MOD
            cur[2]=(prev[1]+prev[3])%MOD;
            cur[3]=prev[2];
            cur[4]=(prev[2]+prev[3])%MOD;
            prev = cur[:]
        sol=sum(cur)%MOD
        return sol