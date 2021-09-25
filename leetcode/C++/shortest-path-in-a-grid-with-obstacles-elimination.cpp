class POINT {
public:
    int y,x,d,r;
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // 1. declare variable
        int m=grid.size(), n=grid[0].size(), ny,nx,dx[]={1,-1,0,0}, dy[]={0,0,-1,1};
        POINT p = {0,0,0,0};
        vector<vector<int>> d(m,vector<int>(n,-1)), r(m,vector<int>(n,0));
        // 2. init queue for bfs
        queue<POINT> q;
        d[0][0]=0; q.push(p);
        // 3. traverse
        while(!q.empty()){
            p = q.front(); q.pop();
            if(p.y==m-1 && p.x==n-1) return p.d; 
            for(int i=0; i<4; ++i){
                ny=p.y+dy[i]; nx=p.x+dx[i];
                if(ny<0 || ny>=m || nx<0 || nx>=n) continue;
                // 3.1 first visit
                if(d[ny][nx]==-1 && p.r+grid[ny][nx]<=k){
                    d[ny][nx]=p.d+1; r[ny][nx]=p.r+grid[ny][nx];
                    q.push({ny,nx,p.d+1,p.r+grid[ny][nx]});
                }
                // 3.2 already visist but, smaller remove count
                else if(d[ny][nx]>=0 && p.r+grid[ny][nx]<r[ny][nx]){
                    d[ny][nx]=p.d+1; r[ny][nx]=p.r+grid[ny][nx];
                    q.push({ny,nx,p.d+1,p.r+grid[ny][nx]});
                }
            }
        }
        return -1;
    }
};