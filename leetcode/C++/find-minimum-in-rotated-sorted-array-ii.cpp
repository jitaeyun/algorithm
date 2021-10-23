class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=(int)nums.size()-1,m=0,sol=nums[0];
        while(l<=r){
            m=(l+r)/2;
            sol=min(sol,nums[m]);
            if(nums[m]>nums[r]) l=m+1;
            else if(nums[m]<nums[r]) r=m-1;
            else --r;
        }
        return sol;
    }
};