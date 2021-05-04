class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i=1, c=0; i<nums.size(); ++i) {
            if(nums[i-1]>nums[i]) {
                if(++c==2) return false;
                else if(i>1 && nums[i-2] > nums[i]) nums[i]=nums[i-1];
            }
        }
        return true;
    }
};