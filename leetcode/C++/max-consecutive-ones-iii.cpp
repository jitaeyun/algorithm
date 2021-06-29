class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int sol=0,t=0;
        for(int l=0,r=0; r<nums.size(); ){
            if(nums[r]==1) {++t; ++r;}
            else if(k>0) {--k; ++t; nums[r++]=-1;}
            else if(nums[l]==0) ++l;
            else if(nums[l]==1) {++l; --t;}
            else {++l; --t; ++k;}
            if(l>=r) ++r;
            sol=max(sol,t);
        }
        return sol;
    }
};