class Solution {
public:
    int bitwiseComplement(int n) {
        int tot=1<<30;
        if(n==0) return 1;
        for(; tot>0; tot>>=1) if(tot&n) break;
        tot=(tot<<1)-1;
        return tot^n;
    }
};