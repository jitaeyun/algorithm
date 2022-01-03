class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int sol = -1;
        vector<int> t(n+1, 0), td(n+1, 0);
        for(vector<int>& v : trust) {++td[v[1]]; ++t[v[0]];} 
        for(int i=1; i<n+1; ++i){
            if(td[i]==n-1 && t[i]==0) {
                if(sol==-1) sol = i;
                else return -1;
            }
        }
        return sol;
    }
};