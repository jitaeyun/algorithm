class Solution {
public:
    set<vector<int>> sol;
    void dfs(vector<int>& nums, int visit, int pos){
        if(pos==nums.size()) {
            vector<int> v;
            for(int i=0, p=1; i<nums.size(); ++i, p<<=1){
                if(visit&p) v.push_back(nums[i]);
            }
            sol.insert(v);
            return;
        }
        dfs(nums,visit,pos+1);
        dfs(nums,visit|(1<<pos),pos+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0,0);
        return vector<vector<int>>(sol.begin(),sol.end());
    }
};