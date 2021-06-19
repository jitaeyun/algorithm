class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[2][1001], MODULO = 1000000007;
        for(int i=0; i<k+1; ++i) dp[1][i]=dp[0][i]=0;
        dp[1][0]=dp[0][0]=1;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=(i*(i-1))/2&&j<=k; ++j){
                dp[1][j]=dp[1][j-1]+dp[0][j];
                if(j>=i) dp[1][j]-=dp[0][j-i];
                if(dp[1][j]<0) dp[1][j]+=MODULO;
                dp[1][j]%=MODULO;
            }
            for(int j=0; j<=k; ++j) dp[0][j]=dp[1][j];
        }
        return dp[1][k];
    }
};