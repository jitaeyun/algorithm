class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sol;
        vector<pair<int,int>> v;
        for(int i=0; i<points.size(); ++i){
            v.push_back({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
        sort(v.begin(),v.end());
        for(int i=0; i<k; ++i) sol.push_back(points[v[i].second]);
        return sol;
    }
};