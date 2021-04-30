class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> sol,m(bound+1,0);
        int lx=1, ly=1, n;
        if(x!=1) lx=int(floor(log(bound) / log(x))) + 1;
        if(y!=1) ly=int(floor(log(bound) / log(y))) + 1;
        for(int i=0, px=1; i<lx; ++i, px*=x){
            for(int j=0, py=1; j<ly; ++j, py*=y){
                n=px+py;
                if(n<=bound&&m[n]++==0) sol.push_back(n);
            }
        }
        return sol;
    }
};