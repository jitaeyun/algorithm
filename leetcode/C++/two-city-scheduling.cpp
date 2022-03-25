class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1000000));
        dp[0][0]=0;
        for(int i=0; i<costs.size(); ++i){
            for(int j=0,k=i; j<=i; ++j,--k){
                if(j>n || k>n) continue;
                if(j+1<=n) dp[j+1][k]=min(dp[j+1][k], dp[j][k]+costs[i][0]);
                if(k+1<=n) dp[j][k+1]=min(dp[j][k+1], dp[j][k]+costs[i][1]);
            }
        }
        return dp.back().back();
    }
};