class Solution {
public:
    int subSolve(vector<int> &v, string &s, int &idx){
        int st=idx, end=v[s[idx]-'a'];
        for(; idx<s.length()&& idx<end; ++idx){
            end=max(end, v[s[idx]-'a']);
        }
        return end-st+1;
    }
    vector<int> partitionLabels(string s) {
        vector<int> sol, v(26,0);
        int idx = 0;
        for(int i=0; i<s.length(); ++i){
            v[s[i] - 'a'] = i;
        }
        for(int i=0; i<s.length(); ++i){
            sol.push_back(subSolve(v, s, i));
        }
        return sol;
    }
};