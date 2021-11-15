class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size());
        int m_idx=0;
        for(int i=0,idx=-1; i<nums.size(); ++i){
            idx=-1;
            if(i==0) {dp[i].push_back(nums[i]); continue;}
            for(int j=0; j<i; ++j){
                if(nums[i]%dp[j].back()==0 && (idx==-1 || dp[idx].size()<dp[j].size())) idx=j;
            }
            if(idx>=0) dp[i]=dp[idx];
            dp[i].push_back(nums[i]);
            if(dp[m_idx].size()<dp[i].size()) m_idx=i;
        }
        return dp[m_idx];
    }
};