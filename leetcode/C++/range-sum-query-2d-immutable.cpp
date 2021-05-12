class NumMatrix {
public:
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); ++i){
            vector<int> v; int pSum=0, t;
            for(int j=0; j<matrix[i].size(); ++j){
                pSum+=matrix[i][j];
                if(!m.empty()) t=pSum+m.back().at(j);
                else t=pSum;
                v.push_back(t);
            }
            m.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sol=m[row2][col2];
        if(row1) sol-=m[row1-1][col2];
        if(col1) sol-=m[row2][col1-1];
        if(row1&&col1) sol+=m[row1-1][col1-1];
        return sol;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */