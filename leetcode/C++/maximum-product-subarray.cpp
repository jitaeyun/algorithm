class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sol=nums[0],mx=nums[0],mn=nums[0];
        for(int i=1,j=0,k=0; i<nums.size(); ++i){
            mx*=nums[i]; mn*=nums[i]; j=max(mx,mn); k=min(mx,mn);
            mx=max(j,nums[i]); mn=min(k,nums[i]);
            sol=max(sol,mx);
        }
        return sol;
    }
};