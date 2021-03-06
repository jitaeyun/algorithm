class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int sol=0;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1,0));
        for(int i=0; i<nums1.size(); ++i){
            for(int j=0; j<nums2.size(); ++j){
                if(nums1[i]==nums2[j]) {
                    dp[i+1][j+1]=dp[i][j]+1;
                    sol=max(sol,dp[i+1][j+1]);
                }
            }
        }
        return sol;
    }
};