class Solution {
public:
    int isCheck(vector<int>& nums, int &target, int &n){
        int g=0, sum=0;
        for(int i=0; i<nums.size(); ++i){
            if(sum+nums[i]<=target) sum+=nums[i];
            else {
                ++g;
                sum = nums[i];
            }
            if(sum>target) return n+1;
        }
        if(sum>0) ++g;
        return g;
    }
    int splitArray(vector<int>& nums, int m) {
        int sol=0, l=0, r=1000000000, mid=0, g=0;
        while(l<=r){
            mid=(l+r)/2;
            g=isCheck(nums, mid, m);
            if(g>m) l=mid+1;
            else {
                r=mid-1;
                sol=mid;
            }
        }
        return sol;
    }
};