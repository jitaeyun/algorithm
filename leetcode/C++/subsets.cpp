class Solution {
public:
    vector<vector<int>> sol;
    vector<int> v;
    void dfs(vector<int>& nums, int cur){
        if(cur==nums.size()) {
            sol.push_back(v);
            return;
        }
        dfs(nums,cur+1);
        v.push_back(nums[cur]);
        dfs(nums,cur+1);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return sol;
    }
};