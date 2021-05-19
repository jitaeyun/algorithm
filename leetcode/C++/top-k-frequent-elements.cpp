class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> v;
        vector<int> sol;
        for(int i=0; i<nums.size(); ++i){
            if(i==0 || nums[i-1]!=nums[i]) v.push_back({nums[i],1});
            else ++v.back().second;
        }
        sort(v.begin(),v.end(),[](pair<int,int> &a, pair<int,int> &b){return a.second>b.second;});
        for(int i=0; i<k; ++i) sol.push_back(v[i].first);
        return sol;
    }
};