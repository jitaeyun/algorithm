class Solution {
public:
    const int mod = 1000000007;
    int numDecodings(string s) {
        long c=0,p=1,n=0;
        int num=0;
        if(s[0]=='*') c=9;
        else if(s[0]!='0') c=1;
        for(int i=1; i<s.length(); ++i){
            if(s[i]=='*') n+=c*9;
            else if(s[i]>='1' && s[i]<='9') n+=c;
            if(s[i]=='*' && s[i-1]=='*') n+=p*15;
            else if(s[i]=='*'){
                if(s[i-1]=='1') n+=p*9;
                else if(s[i-1]=='2') n+=p*6;
            }
            else if(s[i-1]=='*') {
                if(s[i]>'6') n+=p;
                else n+=p*2;
            }
            else {
                num=(s[i-1]-'0')*10+(s[i]-'0');
                if(num>=10 && num<=26) n+=p;
            }
            n%=mod; p=c; c=n; n=0;
        }
        return c;
    }
};