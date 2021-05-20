class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int sol=0, ny,nx,cy,cx,dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]=='0') continue;
                ++sol; q.push({i,j}); grid[i][j]='0';
                for(; !q.empty(); q.pop()){
                    cy=q.front().first; cx=q.front().second;
                    for(int k=0; k<4; ++k){
                        ny=cy+dy[k]; nx=cx+dx[k];
                        if(ny<0 || nx<0 || ny>=grid.size() || nx>=grid[0].size()) continue;
                        else if(grid[ny][nx]=='0') continue;
                        q.push({ny,nx}); grid[ny][nx]='0';
                    }
                }
            }
        }
        return sol;
    }
};