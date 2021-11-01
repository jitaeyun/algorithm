class Solution {
public:
    int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1}, ny,nx ,cy,cx;
    void traverse(vector<vector<char>>& board, vector<vector<int>> &visit, vector<int> &border_check, int &y, int &x){
        if(board[y][x]=='X' || visit[y][x]>=0) return;
        queue<pair<int,int>> q;
        int g=border_check.size();
        border_check.push_back(0);
        q.emplace(y,x);
        visit[y][x]=g;
        while(!q.empty()){
            cy=q.front().first; cx=q.front().second; q.pop();
            if(cy==0 || cy+1 == board.size() || cx==0 || cx+1 == board[0].size()) border_check[g]=1;
            for(int i=0; i<4; ++i){
                ny=cy+dy[i]; nx=cx+dx[i];
                if(ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size()) continue;
                else if(board[ny][nx]=='X' || visit[ny][nx]>=0) continue;
                visit[ny][nx]=g; q.emplace(ny,nx);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visit(board.size(), vector<int>(board[0].size(),-1));
        vector<int> border_check;
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                traverse(board,visit,border_check,i,j);
            }
        }
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(visit[i][j]>=0 && border_check[visit[i][j]]==0) board[i][j]='X';
            }
        }
    }
};