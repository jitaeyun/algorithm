class Solution {
public:
    int dp[101][101][2];
    int traverse(vector<int> &piles,int f, int m, int idx){
        if(idx>=piles.size()) return 0;
        else if(dp[m][idx][f]) return dp[m][idx][f];
        int sol=0;
        if(f==0) sol=1000001;
        for(int i=0,j=0; i+idx<piles.size() && i<2*m; ++i){
            if(f) {
                j+=piles[i+idx];
                sol=max(sol,j+traverse(piles,f^1,max(m,i+1),i+1+idx));
            }
            else sol=min(sol,traverse(piles,f^1,max(m,i+1),i+1+idx));
        }
        return dp[m][idx][f]=sol;
    }
    int stoneGameII(vector<int>& piles) {
        for(int i=0; i<piles.size(); ++i) for(int j=0; j<piles.size(); ++j) dp[i][j][0]=dp[i][j][1]=0;
        return traverse(piles,1,1,0);
    }
};