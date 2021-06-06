class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int sol=0,n=0;
        unordered_set<int> us(nums.begin(),nums.end());
        if(nums.empty()) return 0;
        for(int i=0,t=0,s=0; i<nums.size();){
            if(s==0){
                if(us.find(nums[i])==us.end()) ++i;
                else {n=s=1; t=nums[i]; us.erase(t);}
            }
            else if(s==1){
                if(us.find(--t)==us.end()) {t=nums[i]; s=2;}
                else {++n; us.erase(t);}
            }
            else {
                if(us.find(++t)==us.end()) {s=0; ++i;}
                else {++n; us.erase(t);} 
            }
            sol=max(sol,n);
        }
        return sol;
    }
};