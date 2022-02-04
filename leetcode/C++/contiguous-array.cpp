class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sol=0;
        unordered_map<int,int> um;
        um[0]=-1;
        for(int i=0,t=0; i<nums.size(); ++i) {
            (nums[i]==0)? --t : ++t;
            um[t]=i;
        }
        for(int i=0,t=0; i<nums.size(); ++i) {
            sol=max(sol,um[t]-i+1);
            (nums[i]==0)? --t : ++t;
        }
        return sol;
    }
};