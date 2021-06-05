class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p=0,l=0,r=nums.size()-1;
        for(int i=1; i<nums.size(); ++i) if(nums[p++]>nums[i]) break;
        if(nums[p]<=target && target<=nums.back()) l=p; 
        else r=p-1;
        while(l<=r){
            p=(l+r)/2;
            if(nums[p]<target) l=p+1;
            else if(nums[p]>target) r=p-1;
            else return p;
        }
        return -1;
    }
};