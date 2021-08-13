class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), y=0,x=0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j]==0) {
                    if(i==0) y=1;
                    if(j==0) x=1;
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        for(int i=1; i<m; ++i) {
            if(matrix[i][0]==0) for(int j=1; j<n; ++j) matrix[i][j]=0; 
        }
        for(int i=1; i<n; ++i){
            if(matrix[0][i]==0) for(int j=1; j<m; ++j) matrix[j][i]=0;
        }
        for(int i=0; i<n&&y; ++i) matrix[0][i]=0;
        for(int i=0; i<m&&x; ++i) matrix[i][0]=0;
    }
};