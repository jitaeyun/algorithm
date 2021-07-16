class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s;
        int t,l,r;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1; i>=3; --i){
            for(int j=i-1; j>=2; --j){
                l=0; r=j-1;
                while(l<r){
                    t=nums[l]+nums[r]+nums[j]+nums[i];
                    if(t==target) {
                        s.insert({nums[l],nums[r],nums[j],nums[i]}); 
                        ++l;
                    }
                    else if(t<target) ++l;
                    else --r;
                }
            }
        }
        return vector<vector<int>>(s.begin(), s.end());
    }
};