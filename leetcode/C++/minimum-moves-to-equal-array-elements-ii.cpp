class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sol=0;
        sort(nums.begin(), nums.end());
        for(int i=0,t=nums[nums.size()/2]; i<nums.size(); ++i){
            sol+=(t>nums[i])? t-nums[i] : nums[i]-t;
        }
        return sol;
    }
};