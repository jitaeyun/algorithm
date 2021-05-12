class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        for(int i=0,l,r,t; i<nums.size(); ++i){
            if(i&&nums[i-1]==nums[i]) continue;
            l=i+1; r=nums.size()-1;
            while(l<r){
                t=nums[i]+nums[l]+nums[r];
                if(t>0) --r;
                else if(t<0) ++l;
                else {
                    sol.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) ++l;
                    while(l<r && nums[r]==nums[r-1]) --r;
                    ++l; --r;
                }
            }
        }
        return sol;
    }
};