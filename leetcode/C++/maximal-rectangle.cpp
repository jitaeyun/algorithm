class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int sol=0;
        if(matrix.empty()) return sol;
        vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(),0));
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(),0));
        int s=0,e=0,t=0;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=(int)matrix[0].size()-1; j>=0; --j){
                if(j+1 < matrix[0].size()) m[i][j]=m[i][j+1];
                if(matrix[i][j]=='1') ++m[i][j];
                else m[i][j]=0;
            }
        }
        for(int j=0; j<matrix[0].size(); ++j){
            s=e=0;
            while(s<matrix.size()){
                while(s<matrix.size() && m[s][j]==0) ++s;
                for(e=s; e<matrix.size(); ++e) if(m[e][j]==0) break;
                --e;
                for(int d=0; d<=e-s; ++d){
                    for(int i=s; i+d<=e; ++i) {
                        if(d==0) t=dp[i][i+d]=m[i][j];
                        else dp[i][i+d]=min(dp[i][i+d-1], dp[i+d][i+d]);
                        sol = max(sol, dp[i][i+d]*(d+1));
                    }
                }
                s=e+1;
            }
        }
        return sol;
    }
};