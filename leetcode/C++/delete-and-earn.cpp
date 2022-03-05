class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int cs=0, cn=0, ps=0, pn=0; 
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> v;
        for(int i=0; i<nums.size(); ++i){
            if(v.empty() || v.back().first != nums[i]) v.push_back({nums[i], nums[i]});
            else v.back().second += nums[i];
        }
        for(int i=(int)v.size()-1; i>=0; --i, ps=cs, pn=cn){
            cn=max(ps, pn);
            cs=pn+v[i].second;
            if(i+1<v.size() && v[i].first+1<v[i+1].first) cs=max(cs, ps+v[i].second);
        }
        return max(cs,cn);
    }
};