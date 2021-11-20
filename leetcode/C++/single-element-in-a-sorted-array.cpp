class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=(int)nums.size()-1,m=0;
        while(l<r){
            m=(l+r)/2;
            if(nums[m]==nums[m-1]) ++m;
            if((r-m+1)%2) l=m;
            else r=m-1;
        }
        return nums[l];
    }
};