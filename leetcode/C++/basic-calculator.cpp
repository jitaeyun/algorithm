class Solution {
public:
    stack<pair<int,int>> st, tst;
    void subCalculate(){
        int sol=0, m=1;
        while(!st.empty() && (st.top().first==0 || st.top().second!='(')){
            tst.push(st.top()); 
            st.pop();
        }
        if(!st.empty()) st.pop();
        while(!tst.empty()){
            if(tst.top().first==0) sol+=(m*tst.top().second);
            else if(tst.top().second=='+') m=1;
            else m=-1;
            tst.pop();
        }
        st.push({0,sol});
    }
    int calculate(string s) {
        int num=0;
        for(int i=0; i<s.length(); ++i){
            if(s[i]==' ') continue;
            else if(s[i]>='0' && s[i]<='9'){
                num = 10*num + (s[i]-'0');
                if((i+1<s.length() && !(s[i+1]>='0'&&s[i+1]<='9')) || i+1==s.length()) {
                    st.push({0,num});
                    num=0;
                }
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='(') st.push({1,s[i]});
            else if(s[i]==')') subCalculate();
        }
        subCalculate();
        return st.top().second;
    }
};