class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> sol = {0};
        for(int i=1,m=1; i<=n; ++i,m*=2) {
            for(int j=sol.size()-1; j>=0; --j) sol.push_back(sol[j]+m);
        }
        return sol;
    }
};