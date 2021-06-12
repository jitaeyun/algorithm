class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,sol=0;
        vector<int> visit(26,0);
        int mx=0;
        for(; r<s.length(); ++r){
            ++visit[s[r]-'A'];
            if(visit[s[r]-'A']>visit[mx]) mx=s[r]-'A';
            if(r-l+1>k+visit[mx]) --visit[s[l++]-'A'];
            sol=max(sol,r-l+1);
        }
        return sol;
    }
};