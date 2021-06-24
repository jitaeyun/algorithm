class Solution {
public:
    const int modulo = 1000000007;
    int path[50][50][50], visit[50][50][50];
    void updatePath(int &m, int &n, int &c){
        int dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
        int ny,nx, sol=0;
        for(int y=0; y<m; ++y){
            for(int x=0; x<n; ++x){
                if(visit[y][x][c]==0) continue;
                for(int i=0; i<4; ++i){
                    ny=y+dy[i]; nx=x+dx[i];
                    if(ny<0 || ny>=m || nx<0 || nx>=n) continue;
                    visit[ny][nx][c+1]=1;
                    path[ny][nx][c+1]+=path[y][x][c];
                    path[ny][nx][c+1]%=modulo;
                }
            }
        }
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int sol=0,ny,nx;
        int dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
        for(int i=0; i<m; ++i) 
            for(int j=0; j<n; ++j) 
                for(int k=0; k<maxMove; ++k) 
                    path[i][j][k]=visit[i][j][k]=0;
        path[startRow][startColumn][0]=1;
        visit[startRow][startColumn][0]=1;
        for(int i=0; i<maxMove-1; ++i) updatePath(m,n,i);
        for(int y=0; y<m; ++y){
            for(int x=0; x<n; ++x){
                for(int i=0; i<4; ++i){
                    ny=y+dy[i]; nx=x+dx[i];
                    if(ny<0 || ny>=m || nx<0 || nx>=n) {
                        for(int j=0; j<maxMove; ++j) {
                            sol+=path[y][x][j]; 
                            sol%=modulo;
                        }
                    }
                }
            }
        }
        return sol;
    }
};