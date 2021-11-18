class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> sol;
        for(int i=0,t=0; i<nums.size(); ++i){
            t=abs(nums[i])-1;
            if(nums[t]>0) nums[t]*=-1;
        }
        for(int i=0; i<nums.size(); ++i) if(nums[i]>0) sol.push_back(i+1);
        return sol;
    }
};