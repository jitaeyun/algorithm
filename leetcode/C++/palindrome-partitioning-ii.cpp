class Solution {
public:
    int minCut(string s) {
        int len=s.length();
        vector<vector<int>> dp(len,vector<int>(len,0));
        vector<int> sol(len,0);
        for(int i=0; i<len; ++i){
            for(int j=0; i+j<len; ++j){
                if(s[j]==s[i+j]){
                    dp[j][i+j] = (i<=1)? 1 : dp[j+1][i+j-1];
                }
            }
        }
        for(int i=0; i<len; ++i){
            sol[i] = (dp[0][i]==1)? 0 : i;
            for(int j=0; j<i; ++j){
                if(dp[j+1][i]) sol[i]=min(sol[i],sol[j]+1);
            }
        }
        return sol[len-1];
    }
};