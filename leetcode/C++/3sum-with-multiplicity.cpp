class Solution {
public:
    unordered_map<int,int> um;
    const int MOD = 1000000007;
    long long select(long long &a, long long &b, long long &c){
        long long sol = 0;
        long long i=um[a],j=um[b],k=um[c];
        if(a==b && b==c){
            if(i<3) return 0;
            return (((i)*(i-1)*(i-2))/6)%MOD;
        }
        else if(a==b){
            if(i<2) return 0;
            return ((((i)*(i-1))/2)*k)%MOD;
        }
        else if(b==c) {
            if(j<2) return 0;
            return ((((j)*(j-1))/2)*i)%MOD;
        }
        else if(a==c){
            if(i<2) return 0;
            return ((((i)*(i-1))/2)*j)%MOD;
        }
        return (i*j*k)%MOD;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        long long sol = 0;
        for(int &n : arr) ++um[n];
        for(long long i=0,k=0; i<=target; ++i){
            if(um.find(i)==um.end()) continue;
            for(long long j=i; j<=target; ++j){
                if(um.find(j)==um.end()) continue;
                k=target-i-j;
                if(k<j || k<0 || um.find(k)==um.end()) continue;
                sol += select(i,j,k);
                sol%=MOD;
            }
        }
        return sol;
    }
};