class Solution {
public:
    int minDistance(string word1, string word2) {
        int l=0;
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),0));
        for(int i=0; i<word1.length(); ++i){
            for(int j=0; j<word2.length(); ++j){
                if(word1[i]==word2[j]){
                    dp[i][j]=1;
                    if(i*j) dp[i][j]+=dp[i-1][j-1];
                }
                else{
                    if(i) dp[i][j]=max(dp[i][j],dp[i-1][j]);
                    if(j) dp[i][j]=max(dp[i][j],dp[i][j-1]);
                }
                if(l<dp[i][j]) l=dp[i][j];
            }
        }
        return word1.length()+word2.length()-2*l;
    }
};