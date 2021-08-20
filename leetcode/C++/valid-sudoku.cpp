class Solution {
public:
    bool isCheckRow(vector<vector<char>>& board, int &idx){
        unordered_set<char> us;
        for(int i=0; i<board[0].size(); ++i){
            if(board[idx][i]=='.') continue;
            if(us.find(board[idx][i])!=us.end()) return false;
            us.insert(board[idx][i]);
        }
        return true;
    }
    bool isCheckCol(vector<vector<char>>& board, int &idx){
        unordered_set<char> us;
        for(int i=0; i<board.size(); ++i){
            if(board[i][idx]=='.') continue;
            if(us.find(board[i][idx])!=us.end()) return false;
            us.insert(board[i][idx]);
        }
        return true;
    }
    bool isCheckCube(vector<vector<char>>& board, int &idx){
        int sr=(idx/3)*3, sl=(idx%3)*3;
        unordered_set<char> us;
        for(int i=sr; i<sr+3; ++i){
            for(int j=sl; j<sl+3; ++j){
                if(board[i][j]=='.') continue;
                if(us.find(board[i][j])!=us.end()) return false;
                us.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i){
            if(!(isCheckRow(board,i)&&isCheckCol(board,i)&&isCheckCube(board,i))) return false;
        }
        return true;
    }
};