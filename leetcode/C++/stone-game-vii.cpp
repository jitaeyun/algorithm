class Solution {
public:
    int traverse(vector<vector<int>> &dp ,vector<int> &s,int sum, int l, int r){
        if(l>=r) return 0;
        else if(dp[l][r]) return dp[l][r];
        return dp[l][r]=max(sum-s[l] - traverse(dp, s, sum-s[l], l+1, r),sum-s[r] - traverse(dp, s,sum-s[r], l, r-1));
    }
    int stoneGameVII(vector<int>& stones) {
        int s=0;
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),0));
        for(int &t : stones) s+=t;
        return traverse(dp,stones,s,0,stones.size()-1);
    }
};