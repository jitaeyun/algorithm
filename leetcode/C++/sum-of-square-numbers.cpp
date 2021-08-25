class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i=0,j=0,k=0; i*i<=c; ++i){
            if((j=c-i*i)<0) continue;
            k=sqrt(j);
            if(j-k*k<1) return true;
        }
        return false;
    }
};