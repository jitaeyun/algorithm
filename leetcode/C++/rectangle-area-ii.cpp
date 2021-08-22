class Solution {
public:
    const int MOD = 1000000007;
    long long rangeArea(vector<vector<int>>& rectangles, int &prev_x, int &cur_x){
        long long area=0;
        int mx=0;
        // 1. make y points depending on x-axis range and sort
        vector<pair<int,int>> y;
        for(vector<int> &rect : rectangles){
            if(rect[0]<=prev_x&&rect[2]>=cur_x) y.push_back({rect[1],rect[3]});
        }
        sort(y.begin(),y.end());
        // 2. get area of x-axis range and y-axis range
        for(const pair<int,int> &p : y){
            if((mx=max(mx,p.first))>=p.second) continue;
            area+=(long long)(cur_x-prev_x)*(p.second-mx);
            mx=p.second;
        }
        return area;
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long sol = 0;
        // 1. make x points and sort
        vector<int> x;
        for(int i=0; i<rectangles.size(); ++i) {
            x.push_back(rectangles[i][0]);
            x.push_back(rectangles[i][2]);
        }
        sort(x.begin(),x.end());
        // 2. get area depending on x-axis range
        for(int i=1, prev_x=x[0]; i<x.size(); prev_x=x[i++]){
            if(prev_x==x[i]) continue;
            sol+=rangeArea(rectangles, prev_x, x[i]);
        }
        // 3. output
        return sol%MOD;
    }
};