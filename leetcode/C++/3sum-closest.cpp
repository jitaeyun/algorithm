class Solution {
public:
    const int MAX = 100000000;
    int abs(int &a, int &b){
        return (a>b)? a-b : b-a;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int sol=MAX;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1,l,r,t; i>=2; --i){
            l=0; r=i-1;
            while(l<r){
                t=nums[l]+nums[r]+nums[i];
                if(t>target) --r;
                else if(t<target) ++l;
                else return target;
                if(abs(sol,target)>abs(t,target)) sol=t;
            }
        }
        return sol;
    }
};