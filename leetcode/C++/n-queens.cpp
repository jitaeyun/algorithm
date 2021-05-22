class Solution {
public:
    vector<string> v;
    vector<vector<string>> sol;
    void traverseNqueens(int cur, int &n){
        if(cur==n) {
            sol.push_back(v);
            return;
        }
        for(int i=0,j=0,d=0; i<n; ++i){
            for(j=0,d=cur; j<cur; ++j,--d){
                if(v[j][i]=='Q' || (i>=d && v[j][i-d]=='Q') || (i+d<n && v[j][i+d]=='Q')) break;
            }
            if(j==cur) {
                v[cur][i]='Q';
                traverseNqueens(cur+1,n);
                v[cur][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0; i<n; ++i) s.push_back('.');
        for(int i=0; i<n; ++i) v.push_back(s);
        traverseNqueens(0,n);
        return sol;
    }
};