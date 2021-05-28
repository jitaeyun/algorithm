class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int t=0,sol=0,idx=0;
        vector<int> visit(10001,0);
        for(int i=0; i<nums.size(); ++i){
            if(++visit[nums[i]]>1){
                for(; idx<nums.size(); ++idx){
                    --visit[nums[idx]]; t-=nums[idx];
                    if(nums[idx]==nums[i]) {++idx; break;}
                }
            }
            t+=nums[i];
            sol=max(sol,t);
        }
        return sol;
    }
};