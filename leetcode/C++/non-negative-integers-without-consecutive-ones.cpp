class Solution {
public:
    int findIntegers(int n) {
        int sol=0, dp[32]={1,2}, prev=0;
        for(int i=2; i<32; ++i) dp[i]=dp[i-1]+dp[i-2];
        for(int i=30; i>=0; --i){
            if(n&(1<<i)){
                sol+=dp[i];
                if(prev) return sol;
                prev=1;
            }
            else prev=0;
        }
        return sol+1;
    }
};