class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int sol = 0, t=0;
        unordered_map<int,int> um;
        vector<int> v;
        for(int &n : nums) if(um[n]++==0) v.push_back(n);
        for(int &n : v){
            t = um[n-k];
            if(n-k == n) sol += (t>1)? 1 : 0;
            else if(t>0) ++sol;
        }
        return sol;
    }
};