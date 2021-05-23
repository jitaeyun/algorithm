class Solution {
public:
    vector<int> visited,permutation;
    vector<vector<int>> permutations;
    void solve(int cur, vector<int>& nums){
        if(cur==nums.size()) {
            permutations.push_back(permutation);
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            if(visited[i]) continue;
            visited[i]=1; permutation.push_back(nums[i]);
            solve(cur+1,nums);
            visited[i]=0; permutation.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited=vector<int>(nums.size(),0);
        solve(0,nums);
        return permutations;
    }
};