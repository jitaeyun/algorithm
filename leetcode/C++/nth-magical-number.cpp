class Solution {
public:
    int gcd(int num1, int num2){
        if(num2 == 0) return num1;
        return gcd(num2, num1 % num2);
    }
    int nthMagicalNumber(int n, int a, int b) {
        const int modulo=1000000007;
        int mx = max(a,b), mn=min(a,b), common=(a*b)/gcd(a, b);
        long long l=1, r=(long long)mx*n, m=0, t=0;
        while(l<=r){
            m=(l+r)/2;
            t=(m/mx)+(m/mn)-(m/common);
            if(t<n) l=m+1;
            else if(t>n) r=m-1;
            else break;
        }
        return (m-min(m%mx,m%mn))%modulo;
    }
};