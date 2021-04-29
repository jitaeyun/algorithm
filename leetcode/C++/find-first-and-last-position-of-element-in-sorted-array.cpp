class Solution {
public:
    vector<int> sol;
    void binarySearch(vector<int>& nums, int &target, int flag){
        int l=0, r=nums.size()-1, m;
        if(nums.empty()) return;
        while(l<=r){
            m = (l+r)/2;
            if(nums[m]==target){
                sol[flag]=m;
                if(flag==0) r=m-1;
                else l=m+1;
            }
            else if(nums[m]<target) l=m+1;
            else r=m-1;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        sol = {-1,-1};
        binarySearch(nums,target,0);
        binarySearch(nums,target,1);
        return sol;
    }
};