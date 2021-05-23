class Solution {
public:
    vector<int> comb;
    vector<vector<int>> sol;
    void dfs(int &n, int &k, int cur){
        if(comb.size()==k){
            sol.push_back(comb);
            return;
        }
        for(int i=cur+1; i<=n; ++i) {
            comb.push_back(i);
            dfs(n,k,i);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,0);
        return sol;
    }
};