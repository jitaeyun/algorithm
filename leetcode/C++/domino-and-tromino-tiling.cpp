class Solution {
public:
    int numTilings(int n) {
        vector<long> v = {0,1,2,5};
        for(int i=4; i<=n; ++i) v.push_back((2*v[i-1]+v[i-3])%1000000007);
        return v[n];
    }
};