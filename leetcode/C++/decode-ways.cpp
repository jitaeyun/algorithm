class Solution {
public:
    int numDecodings(string s) {
        int prev=1, great_prev=1, cur=1;
        if(s[0]=='0') return 0;
        for(int i=1; i<s.length()&&cur; ++i){
            cur=prev;
            if(s[i]=='0') cur=(s[i-1]=='0' || s[i-1]>'2')? 0 : great_prev;
            else if(s[i]<='6' && s[i-1]>='1' && s[i-1]<='2') cur+=great_prev;
            else if(s[i-1]=='1') cur+=great_prev;
            great_prev=prev;
            prev=cur;
        }
        return cur;
    }
};