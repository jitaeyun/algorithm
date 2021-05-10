class Solution {
public:
    int sIdx,eIdx;
    void expand(string &st, int s, int e){
        for(; s>=0 && e<st.length(); --s, ++e){
            if(st[s]!=st[e]) break;
        }
        ++s; --e;
        if(eIdx-sIdx+1<e-s+1) {sIdx=s; eIdx=e;}
    }
    string longestPalindrome(string s) {
        sIdx=eIdx=0;
        for(int i=1; i<s.length(); ++i){
            if(i>1 && s[i-2]==s[i]) expand(s,i-2,i);
            if(s[i]==s[i-1]) expand(s,i-1,i);
        }
        return s.substr(sIdx,eIdx-sIdx+1);
    }
};