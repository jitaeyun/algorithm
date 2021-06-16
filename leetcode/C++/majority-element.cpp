class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int idx=0,n=1,mIdx=0,mn=0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]==nums[i-1]) {
                if(mn<++n) {mIdx=idx; mn=n;}
            }
            else {idx=i; n=1;}
        }
        return nums[mIdx];
    }
};