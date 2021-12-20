class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> sol;
        sort(arr.begin(), arr.end());
        int mn=arr[1]-arr[0];
        for(int i=2; i<arr.size(); ++i) mn=min(mn,arr[i]-arr[i-1]);
        for(int i=1; i<arr.size(); ++i) if(mn==arr[i]-arr[i-1]) sol.push_back({arr[i-1],arr[i]});
        return sol;
    }
};