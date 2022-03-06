class Solution {
public:
    int countOrders(int n) {
        long long sol = 1;
        for(int i=2*n; i>0; i-=2){
            sol*=((i)*(i-1)/2);
            sol%=1000000007;
        }
        return sol;
    }
};