class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int sol=0;
        for(int i=(1<<30); i>0; i>>=1){
            if(i>right) continue;
            else if(i>left) break;
            left-=i; right-=i; sol|=i;
        }
        return sol;
    }
};