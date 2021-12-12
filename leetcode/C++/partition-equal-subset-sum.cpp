class Solution {
public:
    int subPartition(int idx, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(sum==0) return 1;
        else if(idx >= nums.size() || sum < 0) return 0;
        else if(dp[idx][sum] >= 0) return dp[idx][sum];
        dp[idx][sum] = subPartition(idx+1, sum-nums[idx], nums, dp) | subPartition(idx+1, sum, nums, dp);
        return dp[idx][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int &n : nums) sum+=n;
        if(sum&1>0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2+1,-1));
        return subPartition(0, sum/2, nums, dp) == 1;
    }
};