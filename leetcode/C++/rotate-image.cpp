class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size(),t;
        for(int i=0; i<sz; ++i){
            for(int j=0; j<i; ++j){
                t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        for(int i=0; i<sz; ++i){
            for(int j=0; j<sz/2; ++j){
                t=matrix[i][j];
                matrix[i][j]=matrix[i][sz-1-j];
                matrix[i][sz-1-j]=t;
            }
        }
    }
};