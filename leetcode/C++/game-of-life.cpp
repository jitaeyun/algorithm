class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> v = board;
        int dy[]={0,0,1,-1,-1,-1,1,1};
        int dx[]={1,-1,0,0,-1,1,-1,1};
        int m=board.size(), n=board[0].size();
        int ny=0,nx=0,num=0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                num = 0;
                for(int k=0; k<8; ++k){
                    ny=i+dy[k]; nx=j+dx[k];
                    if(ny<0 || ny>=m || nx<0 || nx>=n) continue;
                    if(v[ny][nx]) ++num;
                }
                if(num<2) board[i][j]=0;
                else if(num==2) continue;
                else if(num==3) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
};