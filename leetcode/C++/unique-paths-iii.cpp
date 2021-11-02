class Solution {
public:
    int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1},ny,nx;
    int sy,sx,ey,ex,count;
    vector<vector<int>> visit;
    int traverse(vector<vector<int>>& grid, int y, int x, int count){
        if(count==0) return y==sy && x==sx;
        int res=0;
        visit[y][x]=1;
        for(int i=0; i<4; ++i){
            ny=y+dy[i]; nx=x+dx[i];
            if(ny<0 || ny>=grid.size() || nx<0 || nx>=grid[0].size() || grid[ny][nx]==-1 || visit[ny][nx]) continue;
            res+=traverse(grid,ny,nx,count-1);
        }
        visit[y][x]=0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        sy=sx=ey=ex=count=0;
        visit=vector<vector<int>>(grid.size(), vector<int>(grid[0].size(),0));
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(grid[i][j]!=-1) ++count; 
                if(grid[i][j]==1) {sy=i; sx=j;}
                else if(grid[i][j]==2) {ey=i; ex=j;}
            }
        }
        return traverse(grid, ey, ex, count-1);
    }
};