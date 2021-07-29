class Solution {
public:
    const int MAX = 1000000000;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int wy = mat.size(), wx = mat[0].size();
        for(int i=0; i<wy; ++i){
            for(int j=0; j<wx; ++j){
                if(mat[i][j]==0) continue;
                mat[i][j]=MAX;
                if(i) mat[i][j]=min(mat[i][j],mat[i-1][j]+1);
                if(j) mat[i][j]=min(mat[i][j],mat[i][j-1]+1);
            }
        }
        for(int i=wy-1; i>=0; --i){
            for(int j=wx-1; j>=0; --j){
                if(mat[i][j]==0) continue;
                if(i+1<wy) mat[i][j]=min(mat[i][j],mat[i+1][j]+1);
                if(j+1<wx) mat[i][j]=min(mat[i][j],mat[i][j+1]+1);
            }
        }
        return mat;
    }
};

/*
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int MAX = mat.size()*mat[0].size()+1, wy=mat.size(), wx=mat[0].size();
        int y,x,ny,nx, dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
        queue<pair<int,int>> q;
        for(int i=0; i<wy; ++i){
            for(int j=0; j<wx; ++j){
                if(mat[i][j]) mat[i][j]=MAX;
                else q.emplace(i,j);
            }
        }
        while(!q.empty()){
            y=q.front().first; x=q.front().second; q.pop();
            for(int i=0; i<4; ++i){
                ny=y+dy[i]; nx=x+dx[i];
                if(ny<0 || ny>=wy || nx<0 || nx>=wx || mat[y][x] + 1 >= mat[ny][nx]) continue;
                mat[ny][nx]=mat[y][x]+1;
                q.emplace(ny,nx);
            }
        }
        return mat;
    }
};
*/