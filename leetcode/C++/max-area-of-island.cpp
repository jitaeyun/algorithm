class Solution {
public:
    int traverse(vector<vector<int>>& grid, int &y, int &x){
        int dy[]={0,0,1,-1}, dx[]={1,-1,0,0}, cy,cx,ny,nx, sol=1;
        queue<pair<int,int>> q;
        q.push({y,x}); grid[y][x]=0;
        while(!q.empty()){
            cy=q.front().first; cx=q.front().second; q.pop();
            for(int i=0; i<4; ++i){
                ny=cy+dy[i]; nx=cx+dx[i];
                if(ny<0 || ny>=grid.size() || nx<0 || nx>=grid[0].size()) continue;
                else if(grid[ny][nx]==0) continue;
                grid[ny][nx]=0; ++sol; q.push({ny,nx});
            }
        }
        return sol;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int sol=0,t;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] && (t=traverse(grid,i,j))>sol) sol=t;
            }
        }
        return sol;
    }
};