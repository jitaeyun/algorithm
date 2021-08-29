class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sol=0; 
        for(long avail=0, idx=0; avail<n;){
            if(idx<nums.size() && avail+1>=nums[idx]) avail+=nums[idx++];
            else{avail=2*avail+1; ++sol;}
        }
        return sol;
    }
};