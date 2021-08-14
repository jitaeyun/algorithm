class Solution {
public:
    int dp[100][100][100];
    Solution(){
        memset(dp,0,sizeof(dp));
    }
    int solve(int l, int r, int k, vector<int>& boxes){
        if(l>r) return 0;
        if(dp[l][r][k]) return dp[l][r][k];
        dp[l][r][k]=solve(l+1,r,0, boxes)+(k+1)*(k+1);
        for(int i=l+1; i<=r; ++i){
            if(boxes[i]==boxes[l]) dp[l][r][k]=max(dp[l][r][k],solve(l+1,i-1,0, boxes)+solve(i,r,k+1, boxes));
        }
        return dp[l][r][k];
    }
    int removeBoxes(vector<int>& boxes) {
        return solve(0,boxes.size()-1,0,boxes);
    }
};