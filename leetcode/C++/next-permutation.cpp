class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        for(int i=(int)nums.size()-1; i>=0; --i){
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[i]<nums[j]){
                    if(idx==-1) idx=j;
                    else if(nums[idx]>nums[j]) idx=j;
                }
            }
            if(idx>-1) {
                swap(nums[i], nums[idx]);
                idx=i;
                break;
            }
        }
        for(int i=++idx,t=idx; i<nums.size(); ++i){
            t=i;
            for(int j=i+1; j<nums.size(); ++j) if(nums[t]>nums[j]) t=j;
            swap(nums[i], nums[t]);
        }
    }
};