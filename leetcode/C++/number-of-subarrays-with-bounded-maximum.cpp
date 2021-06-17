class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int sol=0, idx=0, f=0, prev=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]<left) {
                if(i) sol+=prev;
            }
            else if(nums[i]>right) {
                prev=f=0; 
                idx=i+1;
            }
            else{
                f=1;
                prev=i-idx+1;
                sol+=prev;
            }
        }
        return sol;
    }
};