class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sol=nums[0], t=0;
        for(int &n : nums){
            t=max(t+n,n);
            sol=max(sol,t);
        }
        return sol;
    }
};