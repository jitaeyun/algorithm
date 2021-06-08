class Solution {
public:
    int getSum(int a, int b) {
        long c=0, s=0, sol=0;
        for(long i=1,j=0; j<32; i<<=1,++j){
            s=(i&(a^b^c));
            c=(i&((a&b)|(b&c)|(a&c)))<<1;
            sol|=s;
        }
        return sol;
    }
};