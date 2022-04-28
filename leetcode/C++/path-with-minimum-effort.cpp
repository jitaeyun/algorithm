class Solution {
public:
    int diff(int &a, int &b){
        return (a>b)? a-b : b-a;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c=heights[0].size(), cy=0, cx=0, ny=0, nx=0, val=0, nval=0, d=0;
        int dy[] = {1,-1,0,0}, dx[]={0,0,1,-1};
        vector<vector<int>> dp(r, vector<int>(c, -1));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        dp[0][0]=0; pq.push({0,0,0});
        while(!pq.empty()){
            cy=pq.top()[1]; cx=pq.top()[2]; val=pq.top()[0]; pq.pop();
            if(val>dp[cy][cx]) continue;
            for(int i=0; i<4; ++i){
                ny=cy+dy[i]; nx=cx+dx[i];
                if(ny<0 || ny>=r || nx<0 || nx>=c) continue;
                d = diff(heights[cy][cx], heights[ny][nx]);
                nval = max(val, d);
                if(dp[ny][nx]==-1 || dp[ny][nx]>nval){
                    dp[ny][nx]=nval;
                    pq.push({nval,ny,nx});
                }
            }
        }
        return dp.back().back();
    }
};