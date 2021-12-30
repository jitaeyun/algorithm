class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for(int idx=1, num=0; idx<=k; ++idx){
            num=(10*num+1)%k;
            if(num==0) return idx;
        }
        return -1;
    }
};