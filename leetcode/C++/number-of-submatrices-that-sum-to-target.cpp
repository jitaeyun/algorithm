class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int dp[100][100],y=matrix.size(),x=matrix[0].size(),sol=0,sum=0;
        for(int i=0; i<y; ++i){
            dp[i][0]=matrix[i][0];
            for(int j=1; j<x; ++j){
                dp[i][j]=dp[i][j-1]+matrix[i][j];
            }
        }
        for(int sy=0; sy<y; ++sy){
            for(int sx=0; sx<x; ++sx){
                for(int ex=sx; ex<x; ++ex){
                    sum=0;
                    for(int i=sy; i<y; ++i){
                        sum+=dp[i][ex];
                        if(sx) sum-=dp[i][sx-1];
                        if(sum==target) ++sol;
                    }
                }
            }
        }
        return sol;
    }
};