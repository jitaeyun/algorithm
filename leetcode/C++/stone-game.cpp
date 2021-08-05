class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),0));
        for(int i=0; i<piles.size(); ++i){
            for(int j=0; i+j<piles.size(); ++j){
                if(i==0) dp[j][i+j]=piles[j];
                else dp[j][i+j]=max(piles[j]-dp[j+1][i+j], piles[i+j]-dp[j][i+j-1]);
            }
        }
        return dp[0][piles.size()-1];
    }
};