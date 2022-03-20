class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int sol = -1;
        vector<int> t(7,0), b(7,0), s(7,0);
        for(int i=0; i<tops.size(); ++i){
            ++t[tops[i]]; ++b[bottoms[i]];
            if(tops[i]==bottoms[i]) ++s[tops[i]];
        }
        for(int i=1; i<=6; ++i){
            if(t[i]+b[i]==tops.size()+s[i]){
                if(sol==-1) sol = tops.size() - max(t[i], b[i]);
                sol = min(sol, (int)tops.size() - max(t[i], b[i]));
            }
        }
        return sol;
    }
};