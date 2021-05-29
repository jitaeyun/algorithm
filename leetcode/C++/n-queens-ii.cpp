class Solution {
public:
    int map[9][9];
    int traverse(int c, int &n){
        int sol=0;
        if(c==n) return 1;
        for(int i=0,j=0; i<n; ++i){
            for(j=0; j<c; ++j){
                if(map[j][i] || (i+j>=c && map[j][i+j-c]) || (i+c<n+j && map[j][i+c-j])) 
                    break;
            }
            if(j<c) continue;
            map[c][i]=1;
            sol+=traverse(c+1,n);
            map[c][i]=0; 
        }
        return sol;
    }
    int totalNQueens(int n) {
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) map[i][j]=0;
        return traverse(0,n);
    }
};