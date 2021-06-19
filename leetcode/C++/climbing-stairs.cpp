class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int a=1, b=2, t=0;
        for(int i=3; i<=n; ++i){
            t=a+b;
            a=b;
            b=t;
        }
        return b;
    }
};