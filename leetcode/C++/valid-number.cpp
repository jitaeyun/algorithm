class Solution {
public:
    bool isNumber(string s) {
        int e=0, dot=0, n=0;
        for(int i=0; i<s.length(); ++i){
            if('0'<=s[i]&&s[i]<='9') ++n;
            else if(s[i]=='+'||s[i]=='-'){
                if(i==0 || s[i-1]=='e' || s[i-1]=='E') n=0;
                else return false;
            }
            else if(s[i]=='.'){
                if(dot==0 && e==0) ++dot;
                else return false;
            }
            else if(s[i]=='e'||s[i]=='E'){
                if(e==0 && n > 0) {++e; n=0;}
                else return false;
            }
            else return false;
        }
        return n;
    }
};