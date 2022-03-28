class Solution {
public:
    bool binarySearch(int l, int r, vector<int> &nums, int &target){
        int m = 0;
        while(l<=r){
            m = (l+r)/2;
            if(nums[m]<target) l=m+1;
            else if(nums[m]>target) r=m-1;
            else return true;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int base_idx=-1, l=0, r=(int)nums.size()-1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i-1]>nums[i]) {
                base_idx=i-1;
                break;
            }
        }
        if(base_idx>=0 && nums[0]<=target && target<=nums[base_idx]) r=base_idx;
        else l=base_idx+1;
        return binarySearch(l,r,nums,target);
    }
};