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


/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> us;
        vector<vector<int>> sol;
        vector<int> v;
        string s;
        sort(nums.begin(),nums.end());
        if(!nums.empty()) v.push_back(nums[0]);
        for(int i=1,j=1; i<nums.size(); ++i){
            if(nums[i]==nums[i-1]) ++j;
            else j=1;
            if(j<4) v.push_back(nums[i]);
        }
        for(int i=0,t=0; i<v.size(); ++i){
            for(int j=i+1,k=(int)v.size()-1; j<k;){
                t=v[i]+v[j]+v[k];
                if(t==0) {
                    s=to_string(v[i])+"+"+to_string(v[j])+"+"+to_string(v[k]);
                    if(us.find(s)==us.end()) {
                        sol.push_back({v[i],v[j],v[k]});
                        us.insert(s);
                    }
                    ++j;
                }
                else if(t>0) --k;
                else ++j;
            }
        }
        return sol;
    }
};
*/