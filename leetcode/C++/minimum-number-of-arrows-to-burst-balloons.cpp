class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int sol = 0, l=points[0][0], r=points[0][1];
        for(vector<int> &p : points){
            l=max(l,p[0]); r=min(r,p[1]);
            if(l>r) {++sol; l=p[0]; r=p[1];}
        }
        return sol+1;
    }
};