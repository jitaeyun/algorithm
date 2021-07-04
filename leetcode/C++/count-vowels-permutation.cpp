class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1000000007;
        int prev[]={1,1,1,1,1}, cur[]={1,1,1,1,1}, sol=0;
        for(int i=2; i<=n; ++i){
            cur[0]=prev[1]+prev[2]; cur[0]%=MOD;
            cur[0]+=prev[4]; cur[0]%=MOD;
            cur[1]=(prev[0]+prev[2])%MOD;
            cur[2]=(prev[1]+prev[3])%MOD;
            cur[3]=prev[2];
            cur[4]=(prev[2]+prev[3])%MOD;
            for(int j=0; j<5; ++j) prev[j]=cur[j];
        }
        for(int i=0; i<5; ++i) {
            sol+=cur[i];
            sol%=MOD;
        }
        return sol;
    }
};