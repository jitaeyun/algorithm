class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        vector<int> sol;
        for(int i=0, num=0; i<mat.size(); ++i){
            num = 0;
            for(int j=0; j<mat[0].size(); ++j) if(mat[i][j]==1) ++num;
            v.push_back({num, i});
        }
        sort(v.begin(), v.end());
        for(int i=0; i<k; ++i) sol.push_back(v[i].second);
        return sol;
    }
};