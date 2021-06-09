class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sol=0;
        for(; n>0; n>>=1){
            if((n&1)) ++sol;
        }
        return sol;
    }
};