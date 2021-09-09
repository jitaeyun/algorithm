class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int sol=0;
        vector<vector<int>> dp[4];
        for(int i=0; i<4; ++i) dp[i]=vector<vector<int>>(n,vector<int>(n,1));
        for(vector<int> &m : mines) {
            dp[0][m[0]][m[1]]=dp[1][m[0]][m[1]]=dp[2][m[0]][m[1]]=dp[3][m[0]][m[1]]=0;
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(j>0 && dp[0][i][j]) dp[0][i][j]=dp[0][i][j-1]+1;
                if(j>0 && dp[1][i][n-j-1]) dp[1][i][n-j-1]=dp[1][i][n-j]+1;
                if(i>0 && dp[2][i][j]) dp[2][i][j]=dp[2][i-1][j]+1;
                if(i>0 && dp[3][n-i-1][j]) dp[3][n-i-1][j]=dp[3][n-i][j]+1;
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                sol=max(sol,min(min(dp[0][i][j],dp[1][i][j]),min(dp[2][i][j],dp[3][i][j])));
            }
        }
        return sol;
    }
};