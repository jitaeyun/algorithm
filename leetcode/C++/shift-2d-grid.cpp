class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> v = grid;
        int m=grid.size(), n=grid[0].size();
        int ny=0,nx=0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                nx=j+k; ny=i+nx/n;
                nx%=n; ny%=m;
                v[ny][nx]=grid[i][j];
            }
        }
        return v;
    }
};