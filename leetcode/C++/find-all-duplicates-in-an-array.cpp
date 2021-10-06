class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> sol;
        for(int i=0, n=nums[0]; i<nums.size(); ++i){
            if((n=nums[i])<0) n=-n;
            if(nums[n-1]<0) sol.push_back(n);
            else nums[n-1]=-nums[n-1];
        }
        return sol;
    }
};