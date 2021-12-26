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



/*
class POINT {
public:
    int val,idx;
    POINT() {}
    POINT(int v, int i) : val(v), idx(i) {}
    bool operator()(POINT &a, POINT &b){
        return (a.val==b.val)? a.idx>b.idx : a.val>b.val;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sol;
        priority_queue<POINT,vector<POINT>, POINT> pq;
        for(int i=0; i<points.size(); ++i) {
            pq.push(POINT(points[i][0]*points[i][0]+points[i][1]*points[i][1], i));
        }
        for(int i=0; i<k; ++i) {
            sol.push_back(points[pq.top().idx]); pq.pop();
        }
        return sol;
    }
};
*/