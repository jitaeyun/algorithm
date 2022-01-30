class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        int s = sz - (k%sz);
        vector<int> sol;
        for(int i=s; i<sz; ++i) sol.push_back(nums[i]);
        for(int i=0; i<s; ++i) sol.push_back(nums[i]);
        nums = sol;        
    }
};