class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cur = target, sol=0;
        while(cur>startValue){
            if(cur&1) {++cur; ++sol;}
            cur/=2; ++sol;
        }
        return sol+startValue-cur;
    }
};