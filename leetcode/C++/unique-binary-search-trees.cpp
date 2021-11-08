class Solution {
public:
    int traverse(vector<int> &dp,int l, int h){
        if(l>=h) return 1;
        int sol=0;
        if(dp[h-l]) return dp[h-l];
        for(int i=l,a=0,b=0; i<=h; ++i) sol+=traverse(dp,l,i-1)*traverse(dp,i+1,h);
        return dp[h-l]=sol;
    }
    int numTrees(int n) {
        vector<int> dp(20,0);
        return traverse(dp, 1,n);
    }
};