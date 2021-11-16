class Solution {
public:
    int findNum(int &m, int &n, int &num){
        int sol=0;
        for(int i=1,t=0; i<=m; ++i){
            t=min(num,n*i)/i;
            sol+=t;
            if(t==0) break;
        }
        return sol;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1, r=m*n, mid=0, t=0, sol=1;
        while(l<=r){
            mid=(l+r)/2;
            if((t=findNum(m,n,mid))<k) l=mid+1;
            else {
                sol=mid;
                r=mid-1;
            }
        }
        return sol;
    }
};