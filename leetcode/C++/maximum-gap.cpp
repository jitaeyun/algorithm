class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int sol=0, mx=0, mn=1000000001,t=1000000001, diff;
        if(nums.size()<2) return sol;
        for(int &t : nums){
            mn=min(mn,t);
            mx=max(mx,t);
        }
        if(mx==mn) return sol;
        vector<int> mxm(nums.size()+1,mn), mnm(nums.size()+1,mx+1);
        for(int i=0, idx=0; i<nums.size(); ++i){
            idx=(double)(nums.size()*(nums[i]-mn))/(double)(mx-mn);
            mxm[idx]=max(mxm[idx],nums[i]);
            mnm[idx]=min(mnm[idx],nums[i]);
        }
        for(int i=1,prev=mxm[0]; i<mnm.size(); ++i){
            if(mnm[i]==mx+1) continue;
            sol=max(sol,mnm[i]-prev);
            prev=mxm[i];
        }
        return sol;
    }
};