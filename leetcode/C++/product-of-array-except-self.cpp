class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol={1};
        for(int i=0; i<nums.size()-1; ++i) sol.push_back(sol.back()*nums[i]);
        for(int i=nums.size()-2,t=nums.back(); i>=0; t*=nums[i--]) sol[i]*=t;
        return sol;
    }
};

/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size(),1);
        for(int i=(int)nums.size()-2; i>=0; --i) sol[i]=sol[i+1]*nums[i+1];
        for(int i=1,t=1; i<nums.size(); ++i) {t*=nums[i-1]; sol[i]*=t;}
        return sol;
    }
};
*/