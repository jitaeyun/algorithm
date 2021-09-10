class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long,int>> v(nums.size());
        unordered_map<long,int>::iterator it;
        int sol=0,sum=0;
        long diff=0;
        for(int i=1; i<nums.size(); ++i){
            for(int j=0; j<i; ++j,sol+=sum){
                diff=(long)nacums[i]-nums[j];
                sum = ((it=v[j].find(diff))!=v[j].end())? it->second : 0;
                v[i][diff]+=sum+1;
            }
        }
        return sol;
    }
};