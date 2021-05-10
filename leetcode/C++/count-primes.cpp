class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int sol=1;
        vector<int> v(n,0);
        for(int i=3; i<n; i+=2){
            if(v[i]++) continue;
            ++sol;
            for(int j=i*3; j<n; j+=i*2) v[j]=1;
        }
        return sol;
    }
};