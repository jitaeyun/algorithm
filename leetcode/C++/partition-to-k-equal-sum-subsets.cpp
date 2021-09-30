class Solution {
public:
    bool checkSubsets(vector<int> &nums, int &visit, int &fin, int &target, int s, int idx){
        if(visit==fin) return true;
        else if(target==s) s=idx=0;
        for(int i=idx; i<nums.size(); ++i){
            if((1<<i)&visit || s+nums[i]>target) continue;
            visit^=(1<<i);
            if(checkSubsets(nums,visit,fin,target,s+nums[i],i+1)) return true;
            visit^=(1<<i);
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target=0, visit=0, fin = (1<<nums.size())-1;
        for(int &n : nums) target+=n;
        if(target%k) return false;
        target/=k;
        return checkSubsets(nums, visit, fin, target, 0, 0);
    }
};