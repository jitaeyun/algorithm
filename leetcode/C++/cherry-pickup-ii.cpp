class Solution {
public:
    int dp[70][70][70];
    int row, col;
    int traverse(int r, int c1, int c2, vector<vector<int>>& grid){
        if(r==row) return 0;
        else if(dp[r][c1][c2]>-1) return dp[r][c1][c2];
        int mx = 0;
        for(int i=max(0,c1-1); i<min(col,c1+2); ++i){
            for(int j=max(0,c2-1); j<min(col, c2+2); ++j){
                if(i==j) continue;
                mx = max(mx, traverse(r+1, i, j, grid));
            }
        }
        return dp[r][c1][c2] = mx + grid[r][c1] + grid[r][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size(); col = grid[0].size();
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                for(int k=0; k<col; ++k) dp[i][j][k]=-1;
            }
        }
        return traverse(0, 0, col-1, grid);
    }
};