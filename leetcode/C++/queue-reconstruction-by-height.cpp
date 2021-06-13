class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> sol;
        sort(people.begin(),people.end(),[](vector<int> &a, vector<int> &b){
            return (a[0]==b[0])? a[1]<b[1] : a[0]>b[0];
        });
        for(vector<int> &v : people) sol.insert(sol.begin()+v[1],v);
        return sol;
    }
};