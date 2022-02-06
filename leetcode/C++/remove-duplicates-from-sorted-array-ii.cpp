class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int MAX_DUPLICATION = 2;
        int idx = 0, cnt = 1;
        for(int i=1; i<nums.size(); ++i){
            if(nums[idx]==nums[i]){if(++cnt<=MAX_DUPLICATION) nums[++idx]=nums[i];}
            else {nums[++idx] = nums[i]; cnt = 1;}
        }
        return idx + 1;
    }
};