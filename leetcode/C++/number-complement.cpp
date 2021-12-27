class Solution {
public:
    int findComplement(int num) {
        int sol=0, idx=1<<30;
        while((num&idx)==0) idx>>=1;
        for(; idx>0; idx>>=1) if((num&idx)==0) sol|=idx; 
        return sol;
    }
};