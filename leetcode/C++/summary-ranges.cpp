class Solution {
public:
    string makeRange(int &a, int &b){
        if(a==b) return to_string(a);
        return to_string(a)+"->"+to_string(b);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> sol;
        if(nums.empty()) return sol;
        int st = nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]!=nums[i-1]+1){
                sol.push_back(makeRange(st, nums[i-1]));
                st = nums[i];
            }
        }
        sol.push_back(makeRange(st, nums.back()));
        return sol;
    }
};