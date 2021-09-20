class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int filled=0, turn=0, decision=0;
        vector<vector<int>> square(3,vector<int>(3,0));
        vector<vector<int>> score(2,vector<int>(8,0));
        for(vector<int> &v : moves){
            square[v[0]][v[1]]=turn;
            if(++score[turn][v[0]]==3 || ++score[turn][3+v[1]]==3) ++decision;
            if(v[0]==v[1]&&++score[turn][6]==3) ++decision;
            if(v[0]+v[1]==2&&++score[turn][7]==3) ++decision;
            if(decision) break;
            turn^=1; ++filled;
        }
        if(decision) return (turn==0)? "A" : "B";
        return (filled==9)? "Draw" : "Pending";
    }
};