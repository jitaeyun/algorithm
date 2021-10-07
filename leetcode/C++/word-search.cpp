
class Solution {
public:
    int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>& board, string &word, int &y, int &x, int l){
        int ny=0,nx=0;
        board[y][x]=-board[y][x];
        if(l+1==word.length()) return true;
        for(int i=0; i<4; ++i){
            ny=y+dy[i]; nx=x+dx[i];
            if(ny<0 || ny>=board.size() || nx<0 || nx>=board[0].size()) continue;
            else if(word[l+1]!=board[ny][nx]) continue;
            if(dfs(board,word,ny,nx,l+1)) return true;
        }
        board[y][x]=-board[y][x];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]==word[0] && dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};

/*
backtraking 이 필요하면, stack보다는 dfs(재귀)가 더 낫다.
*/