class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sol = -1;
        vector<int> v(nums.size()+1,0);
        for(int &n : nums) if(++v[n]>1) {sol=n; break;}
        return sol;
    }
};