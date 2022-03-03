class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sol = 0, sz = 1, p=0;
        if(nums.size()<3) return 0;
        p = nums[1]-nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]-nums[i-1] == p) ++sz;
            else {
                sol += ((sz-2)*(sz-1))/2;
                p = nums[i]-nums[i-1];
                sz = 2;
            }
        }
        sol += ((sz-2)*(sz-1))/2;
        return sol;
    }
};