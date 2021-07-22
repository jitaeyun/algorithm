class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> mn(nums.size(),0);
        int mx=0, t=nums.back();
        for(int i=nums.size()-1; i>=0; --i){
            t=min(t,nums[i]);
            mn[i]=t;
        }
        for(int i=0; i<nums.size()-1; ++i){
            mx=max(nums[i],mx);
            if(mx<=mn[i+1]) return i+1;
        }
        return nums.size();
    }
};