class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int cur[200]={0},next[200], sol=10000;
        for(int i=0; i<triangle.size(); ++i){
            for(int j=0; j<triangle[i].size(); ++j){
                if(j==0) next[j]=cur[j]+triangle[i][j];
                else if(j+1==triangle[i].size()) next[j]=cur[j-1]+triangle[i][j];
                else next[j]=triangle[i][j]+min(cur[j-1],cur[j]);
            }
            for(int j=0; j<triangle[i].size(); ++j) cur[j]=next[j];
        }
        for(int i=0; i<triangle.size(); ++i)
            if(sol>cur[i]) sol=cur[i];
        return sol;
    }
};