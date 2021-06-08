class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y, sol=0;
        for(; z>0; z>>=1){
            if(z&1) ++sol;
        }
        return sol;
    }
};