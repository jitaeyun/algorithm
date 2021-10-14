class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; ++i){
            dp[i]=dp[i-1]+1;
            for(int j=1,k=1; j<=i; ++k,j=k*k){
                dp[i]=min(dp[i],dp[i-j]+1);
            }
        }
        return dp[n];
    }
};