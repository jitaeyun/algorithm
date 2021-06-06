class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> visit(1001,0), sol;
        for(int &t : nums1) visit[t]=1;
        for(int &t: nums2) if(--visit[t]==0) sol.push_back(t);
        return sol;
    }
};