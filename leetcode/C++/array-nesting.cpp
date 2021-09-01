class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int sol=0;
        vector<int> visit(nums.size(),0);
        for(int i=0,n=0,t=0; i<nums.size(); t=++i){
            n=0;
            while(visit[t]==0) {
                visit[t]=1;
                t=nums[t];
                ++n;
            }
            sol=max(sol,n);
        }
        return sol;
    }
};