bool compare(vector<int> &a, vector<int> &b){
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int sol=0, mx=-1;
        sort(intervals.begin(), intervals.end(), compare);
        for(vector<int> &v : intervals){
            if(mx<v[1]) ++sol;
            mx=max(mx,v[1]);
        }
        return sol;
    }
};