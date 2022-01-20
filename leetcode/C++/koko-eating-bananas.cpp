class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=1000000000, m=0, sol=0, n=0;
        while(l<=r){
            m=(l+r)/2; n=0;
            for(int &p : piles) n+=(p/m) + (p%m>0);
            if(n<=h) {sol=m; r=m-1;}
            else l=m+1;
        }
        return sol;
    }
};