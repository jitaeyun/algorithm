class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sol=0, l,r,m,t;
        vector<int> v;
        for(int &n : nums) {
            l=0; r=(int)v.size()-1;
            if(v.empty() || v.back() < n) {
                v.push_back(n);
                sol=v.size();
                continue;
            }
            while(l<=r){
                m=(l+r)/2;
                if(v[m]<n) l=m+1;
                else {t=r=m; --r;}
            }
            v[t]=n;
        }
        return sol;
    }
};
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sol=1;
        vector<int> v(nums.size(),1);
        for(int i=1; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i]) v[i]=max(v[i],v[j]+1);
            }
            sol=max(sol,v[i]);
        }
        return sol;
    }
};
*/