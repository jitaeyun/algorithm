class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> sol;
        vector<int> v;
        int sz = mat.size()*mat[0].size();
        if(sz!=r*c) return mat;
        for(int i=0,y,x; i<sz; ++i){
            y=i/(mat[0].size()); x=i%mat[0].size();
            v.push_back(mat[y][x]);
            if(v.size()==c){
                sol.push_back(v);
                v.clear();
            }
        }
        return sol;
    }
};