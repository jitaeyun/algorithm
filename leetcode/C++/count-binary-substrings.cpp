class Solution {
public:
    int countBinarySubstrings(string s) {
        int num[]={0,0}, state=0, cur, sol=0;
        for(int i=0; i<s.length(); ++i){
            cur=s[i]-'0';
            if(state!=cur) num[cur]=0;
            state=cur;
            if(num[cur^1]>=++num[cur]&&num[cur^1]) ++sol;
        }
        return sol;
    }
};