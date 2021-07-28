class Solution {
public:
    vector<int> sol;
    void devide_conquer(int l, int r){
        if(r-l <=1) return;
        vector<int> v;
        int m = (l+r)/2;
        for(int i=0; i<=r-l; ++i) if(i%2==0) v.push_back(sol[i+l]);
        for(int i=0; i<=r-l; ++i) if(i%2) v.push_back(sol[i+l]);
        for(int i=0; i<=r-l; ++i) sol[i+l]=v[i];
        devide_conquer(l,m);
        devide_conquer(m+1,r);
    }
    vector<int> beautifulArray(int n) {
        for(int i=1; i<=n; ++i) sol.push_back(i);
        devide_conquer(0,n-1);
        return sol;
    }
};