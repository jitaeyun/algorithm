class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> sol,m(bound+1,0);
        int sz;
        for(int i=1; i+1<=bound; i*=x) {
            m[i+1]=1;
            sol.push_back(i+1);
            if(x==1) break;
        }
        sz=sol.size();
        for(int i=y,t=0; i<=bound; i*=y){
            for(int j=0; j<sz; ++j){
                t = i + sol[j] -1;
                if(t<=bound){
                    if(m[t]==0){
                        m[t]=1;
                        sol.push_back(t);
                    }
                }
                else if(i==0) return sol;
                else break;
            }
            if(y==1) break;
        }
        return sol;
    }
};