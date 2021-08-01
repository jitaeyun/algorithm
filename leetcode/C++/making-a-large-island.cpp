class Solution {
public:
    int ny,nx,cy,cx,dy[4]={1,-1,0,0},dx[4]={0,0,1,-1};
    vector<int> group;
    vector<vector<int>> visit;
    void goVisit(int &y, int &x, vector<vector<int>>& grid){
        int group_idx = group.size();
        queue<pair<int,int>> q;
        q.push({y,x});
        group.push_back(1);
        visit[y][x]=group_idx;
        while(!q.empty()){
            cy=q.front().first; cx=q.front().second; q.pop();
            for(int i=0; i<4; ++i){
                ny=cy+dy[i]; nx=cx+dx[i];
                if(ny<0 || ny>=grid.size() || nx<0 || nx>=grid[0].size()) continue;
                if(grid[ny][nx]==0 || visit[ny][nx]) continue;
                q.push({ny,nx});
                visit[ny][nx]=group_idx;
                ++group[group_idx];
            }
        }
    }
    int changeOne(int &y, int &x, vector<vector<int>>& grid){
        int sol=1;
        unordered_set<int> groupList;
        for(int i=0; i<4; ++i){
            ny=y+dy[i]; nx=x+dx[i];
            if(ny<0 || ny>=grid.size() || nx<0 || nx>=grid[0].size()) continue;
            groupList.insert(visit[ny][nx]);
        }
        for(const int &group_key : groupList) sol+=group[group_key];
        return sol;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int sol=0;
        group.push_back(0); //init group
        visit = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(),0));
        //1. visit bfs and make group
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] && visit[i][j]==0) {
                    goVisit(i,j, grid);
                    sol=max(sol,group.back());
                }
            }
        }
        //3. find zero point and change zero --> one and calculate 1 group 
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]==0) sol=max(sol,changeOne(i,j,grid));
            }
        }
        //4. return sol
        return sol;
    }
};