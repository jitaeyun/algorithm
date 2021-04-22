class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> um;
        int s=0, sz=wall.size(), t;
        for(int i=0; i<sz; ++i){
            for(int j=0,l=0; j<wall[i].size()-1; ++j){
                if((t=++um[l+=wall[i][j]])>s) s=t;
            }
        }
        return sz-s;
    }
};