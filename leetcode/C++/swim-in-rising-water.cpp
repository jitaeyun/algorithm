struct POINT {
    int y,x,v;
    bool operator()(POINT &a, POINT &b){
        return a.v > b.v;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int sol = 0, dy[]={0,0,1,-1}, dx[]={1,-1,0,0}, ny=0, nx=0;
        priority_queue<POINT,vector<POINT>, POINT> pq;
        POINT p = {0,0,0};
        pq.push({0,0,grid[0][0]});
        grid[0][0]=-1;
        while(!pq.empty()){
            p=pq.top(); pq.pop();
            sol=max(sol,p.v);
            if(p.y+1==grid.size() && p.x+1==grid[0].size()) break;
            for(int i=0; i<4; ++i){
                ny=p.y+dy[i]; nx=p.x+dx[i];
                if(ny<0 || ny>=grid.size() || nx<0 || nx>=grid[0].size() || grid[ny][nx]==-1) continue;
                pq.push({ny,nx,grid[ny][nx]});
                grid[ny][nx]=-1;
            }
        }
        return sol;
    }
};