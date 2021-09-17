class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sol;
        unordered_map<int,int> um;
        const vector<int> &nums = (nums1.size()>nums2.size())? nums2 : nums1;
        const vector<int> &comps = (nums1.size()>nums2.size())? nums1 : nums2;
        for(const int &n : nums) ++um[n];
        for(const int &n : comps) if(um[n]-->0) sol.push_back(n); 
        return sol;
    }
};