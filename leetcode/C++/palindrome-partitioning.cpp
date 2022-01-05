class Solution {
public:
    vector<vector<string>> sol;
    vector<string> subsol;
    vector<vector<int>> m;
    void dfs(int idx, string &s){
        if(idx>=s.length()) {
            sol.push_back(subsol);
            return;
        }
        for(int i=idx; i<s.length(); ++i){
            if(m[idx][i]) {
                subsol.push_back(s.substr(idx, i-idx+1));
                dfs(i+1, s);
                subsol.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        m = vector<vector<int>>(s.length(), vector<int>(s.length(),0));
        for(int d=0,f=0; d<s.length(); ++d){
            for(int i=0; i+d<s.length(); ++i){
                f = (i+1>i+d-1)? 1 : m[i+1][i+d-1];
                if(f && s[i]==s[i+d]) m[i][i+d]=1;
            }
        }
        dfs(0, s);
        return sol;
    }
};