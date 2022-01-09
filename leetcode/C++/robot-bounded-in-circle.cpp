class Solution {
public:
    bool isRobotBounded(string instructions) {
        int y=0, x=0, d=0;
        int dy[]={1,0,-1,0}, dx[]={0,-1,0,1};
        for(int i=0; i<4; ++i){
            for(char &ins : instructions){
                if(ins == 'L') d=(d+1)%4;
                else if(ins == 'R') d=(d+3)%4;
                else {y+=dy[d]; x+=dx[d];}
            }
            if(y==0 && x==0 && d==0) return true;
        }
        return false;
    }
};