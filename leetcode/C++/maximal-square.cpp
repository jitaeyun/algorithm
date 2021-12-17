class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int sol=0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j]=='0') continue;
                else if(i==0 || j==0) dp[i][j]=1;
                else dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
                sol=max(sol,dp[i][j]);
            }
        }
        return sol*sol;
    }
};`