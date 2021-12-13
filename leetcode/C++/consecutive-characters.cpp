class Solution {
public:
    int maxPower(string s) {
        int sol = 0;
        for(int i=0,n=0; i<s.length(); ++i){
            if(n==0 || s[i-1]==s[i]) ++n;
            else n=1;
            sol=max(sol,n);
        }
        return sol;
    }
};