class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,sol=0,sz=0;
        int ny,nx,cy,cx,dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==1) ++fresh;
                else if(grid[i][j]==2) q.emplace(i,j);
            }
        }
        while(!q.empty()){
            sz=q.size();
            for(int i=0,f=0; i<sz; ++i){
                cy=q.front().first; cx=q.front().second; q.pop();
                for(int j=0; j<4; ++j){
                    ny=cy+dy[j]; nx=cx+dx[j];
                    if(ny<0 || ny>=grid.size() || nx<0 || nx>=grid[0].size()) continue;
                    if(grid[ny][nx]==0 || grid[ny][nx]==2) continue;
                    grid[ny][nx]=2;
                    q.emplace(ny,nx);
                    --fresh;
                    if(f++==0) ++sol;
                }
            }
        }
        return (fresh==0)? sol : -1;
    }
};