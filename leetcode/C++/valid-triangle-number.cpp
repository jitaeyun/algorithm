class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int sol=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1; i>1; --i){
            for(int l=0,r=i-1; l<r;){
                if(nums[l]+nums[r]<=nums[i]) ++l;
                else sol+=(r--)-l;
            }
        }
        return sol;
    }
};