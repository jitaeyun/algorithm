class Solution {
public:
    int availNum(vector<vector<char>>& board, int &y, int &x, int &val){
        int sy=(y/3)*3, sx=(x/3)*3;
        char c=val+'0';
        for(int i=0; i<9; ++i) {
            if(board[y][i]==c || board[i][x]==c) return false; 
        }
        for(int i=sy; i<sy+3; ++i){
            for(int j=sx; j<sx+3; ++j){
                if(board[i][j]==c) return false;
            }
        }
        return true;
    }
    bool solver(vector<vector<char>>& board){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.') continue;
                for(int k=1; k<10; ++k){
                    if(availNum(board,i,j,k)) {
                        board[i][j]=k+'0';
                        if(solver(board)) return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};