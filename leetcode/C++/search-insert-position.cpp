class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=(int)nums.size()-1,m=0 , sol=0;
        while(l<=r){
            m=(l+r)/2;
            if(nums[m]<target){sol=l=m+1;}
            else if(nums[m]>target){sol=m; r=m-1;}
            else {sol=m; break;}
        }
        return sol;
    }
};