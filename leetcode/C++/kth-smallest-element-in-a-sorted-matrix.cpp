class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int sz=matrix.size(), mn=matrix[0][0], mx=matrix[sz-1][sz-1], mid,c=0, idx=0, sol=0;
        while(mn<=mx){
            mid=(mn+mx)/2; c=0; idx=sz-1;
            for(int i=0; i<sz; ++i){
                while(idx>=0 && matrix[i][idx]>mid) --idx;
                c+=idx+1;
            }
            if(k<=c){
                sol=mid;
                mx=mid-1;
            }
            else mn=mid+1;
        }
        return sol;
    }
};