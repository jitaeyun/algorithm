class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sol=0;
        for(int i=0,c=0; i<nums.size(); ++i){
            c = (nums[i])? c + 1 : 0;
            sol=max(sol,c);
        }
        return sol;
    }
};