class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sol=0;
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        for(int i=0,j=0; i<s.size() && j<g.size(); ++i,++j){
            if(s[i]<g[j]) --i;
            else ++sol;
        }
        return sol;
    }
};