class Solution {
public:
    unordered_set<string> us;
    void dfs(int &n, string s, int l, int r){
        if(l<r || l>n || r>n) return;
        if(l==n && r==n) {
            us.insert(s);
            return;
        }
        dfs(n,s+'(',l+1,r);
        dfs(n,s+')',l,r+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        dfs(n,"",0,0);
        for(const string &s : us) sol.push_back(s);
        return sol;
    }
};