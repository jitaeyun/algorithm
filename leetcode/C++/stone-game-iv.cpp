class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; ++i) for(int j=1,k=1; k <= i; ++j, k=j*j) if(dp[i - k] == 0) {dp[i]=1; break;}
        return dp[n] == 1;
    }
};