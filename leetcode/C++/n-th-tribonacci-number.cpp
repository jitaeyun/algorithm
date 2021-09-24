class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp;
        for(int i=0; i<=n; ++i){
            if(i==0) dp.push_back(0);
            else if(i<3) dp.push_back(1);
            else dp.push_back(dp[i-1]+dp[i-2]+dp[i-3]);
        }
        return dp[n];
    }
};