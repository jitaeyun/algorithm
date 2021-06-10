class Solution {
public:
    int traverse(vector<int> &dp, vector<int>& arr, int &i, int &d){
        int sol=1;
        for(int j=i+1; j<=i+d && j<arr.size(); ++j){
            if(arr[i]>arr[j]) sol=max(sol,dp[j]+1);
            else break;
        }
        for(int j=i-1; j>=i-d && j>=0; --j){
            if(arr[i]>arr[j]) sol=max(sol,dp[j]+1);
            else break;
        }
        return dp[i]=sol;
    }
    int maxJumps(vector<int>& arr, int d) {
        int sol=0;
        vector<int> dp(arr.size(),1);
        vector<pair<int,int>> v;
        for(int i=0; i<arr.size(); ++i) v.push_back({arr[i],i});
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); ++i){
            sol=max(sol,traverse(dp,arr,v[i].second,d));
        }
        return sol;
    }
};