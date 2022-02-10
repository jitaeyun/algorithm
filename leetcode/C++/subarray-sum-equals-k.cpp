class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sol=0, s=0;
        unordered_map<int,int> um;
        um[0] = 1;
        for(int &n : nums){
            s+=n;
            sol+=um[s-k];
            ++um[s];
        }
        return sol;
    }
};