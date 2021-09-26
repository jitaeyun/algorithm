class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int sz=board.size(), rn=0, cn=0, rr=0, cr=0;
        for(int i=0; i<sz; ++i){
            for(int j=0; j<sz; ++j){
                if((board[0][0]^board[i][j]^board[i][0]^board[0][j])) return -1;
            }
        }
        for(int i=0; i<sz; ++i){
            rn+=board[0][i]; cn+=board[i][0];
            if((i&1)==board[0][i]) ++rr;
            if((i&1)==board[i][0]) ++cr;
        }
        if(!(rn==sz/2 || rn==(sz+1)/2)) return -1;
        if(!(cn==sz/2 || cn==(sz+1)/2)) return -1;
        if(sz&1){
            if(rr&1) rr=sz-rr;
            if(cr&1) cr=sz-cr;
        }
        else{
            rr=min(sz-rr,rr);
            cr=min(sz-cr,cr);
        }
        return (rr+cr)/2;
    }
};