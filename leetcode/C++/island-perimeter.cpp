class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sol = 0, m = grid.size(), n=grid[0].size();
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]) {
                    sol+=4;
                    if(j && grid[i][j-1]) sol-=2;
                    if(i && grid[i-1][j]) sol-=2;
                }
            }
        }
        return sol;
    }
};