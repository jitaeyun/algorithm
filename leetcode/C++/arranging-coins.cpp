class Solution {
public:
    int arrangeCoins(int n) {
        long l=0, r=(1<<16),m=0,t=0,sol=0;
        while(l<=r){
            m=(l+r)/2;
            t=(m*(m+1))/2;
            if(n<t) r=m-1;
            else {sol=m; l=m+1;}
        }
        return sol;
    }
};