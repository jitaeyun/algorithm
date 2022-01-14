class Solution {
public:
    int myAtoi(string s) {
        long long sol = 0;
        int state=0, minus=0, idx=0;
        for(; idx<s.length(); ++idx) if(s[idx]!=' ') break;
        for(; idx<s.length(); ++idx){
            if(state++==0 && (s[idx]=='-' || s[idx]=='+')) minus = (s[idx]=='-')? 1 : 0;
            else if(s[idx]>='0' && s[idx]<='9') sol=(sol*10)+s[idx]-'0';
            else break;
            if(minus == 0 && sol>=INT_MAX) return INT_MAX;
            else if(minus == 1 && sol>INT_MAX) return INT_MIN;
        }
        return (minus==1)? -sol : sol;
    }
};