class Solution {
public:
    vector<int> sol;
    int traverse(int &y, int &x, int &yd, int &xd, vector<vector<int>>& matrix){
        if(y<0 || y>=matrix.size() || x<0 || x>=matrix[0].size()) return 0;
        if(yd<=0 || xd<=0) return 0;
        for(int i=0; i<xd; ++i) sol.push_back(matrix[y][x+i]);
        for(int i=1; i<yd; ++i) sol.push_back(matrix[y+i][x+xd-1]);
        for(int i=xd-2; i>=0&&yd>1; --i) sol.push_back(matrix[y+yd-1][x+i]);
        for(int i=yd-2; i>0&&xd>1; --i) sol.push_back(matrix[y+i][x]);
        return 1;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        for(int i=matrix.size(), j=matrix[0].size(),y=0,x=0; i>=0 && j>=0; i-=2, j-=2, ++y, ++x){
            if(traverse(y,x,i,j,matrix)==0) break;
        }
        return sol;
    }
};