class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int h=obs.size(), w=obs[0].size();
        vector<int> prev(w,0),cur(w,0);
        if(obs[0][0]==0) cur[0]=1;
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                if(i+j==0 || obs[i][j]) continue;
                if(i) cur[j]+=prev[j];
                if(j) cur[j]+=cur[j-1];
            }
            for(int j=0; j<w; ++j) {prev[j]=cur[j]; cur[j]=0;}
        }
        return prev[w-1];
    }
};