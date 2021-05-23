class Solution {
public:
    vector<vector<int>> sol;
    vector<int> v;
    void dfs(vector<int>& candidates, int idx, int target){
        if(target<=0){
            if(target==0) sol.push_back(v);
            return;
        }
        for(int i=idx; i<candidates.size(); ++i){
            v.push_back(candidates[i]);
            dfs(candidates,i,target-candidates[i]);
            v.pop_back();
        }
    }
    vector<vector<int>>combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,0,target);
        return sol;
    }
};