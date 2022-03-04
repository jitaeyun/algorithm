class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double remain = poured;
        vector<vector<double>> v = vector<vector<double>>(query_row+2);
        int avail=1;
        for(int i=0; i<query_row+2; ++i) v[i] = vector<double>(i+1, 0);
        v[0][0] = remain;
        for(int i=0; i<=query_row&&avail>0; ++i){
            avail=0;
            for(int j=0; j<=i; ++j){
                if(v[i][j]>=1) {
                    v[i][j]-=1;
                    v[i+1][j]+=(v[i][j])/2;
                    v[i+1][j+1]+=(v[i][j])/2;
                    v[i][j]=1;
                    ++avail;
                }
            }
        }
        return v[query_row][query_glass];   
    }
};