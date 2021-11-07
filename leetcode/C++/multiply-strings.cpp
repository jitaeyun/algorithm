class Solution {
public:
    string helper(string &num1, string &num2){
        string sol;
        char ch;
        int c=0,a=0,b=0, i=(int)num1.length()-1, j=(int)num2.length()-1;
        for(; i>=0&&j>=0; --i,--j){
            a=num1[i]-'0'; b=num2[j]-'0';
            sol.push_back((a+b+c)%10+'0');
            c=(a+b+c)/10;
        }
        for(; i>=0; --i) {
            a=num1[i]-'0';
            sol.push_back((a+c)%10+'0');
            c=(a+c)/10;
        }
        for(; j>=0; --j){
            b=num2[j]-'0';
            sol.push_back((b+c)%10+'0');
            c=(b+c)/10;
        }
        if(c) sol.push_back('1');
        for(int i=0; i<sol.length()/2; ++i){
            ch=sol[(int)sol.length()-1-i];
            sol[(int)sol.length()-1-i]=sol[i];
            sol[i]=ch;
        }
        return sol;
    }
    string multiply(string num1, string num2) {
        string sol, oper, num;
        vector<string> v = {"0", num1};
        if(num1=="0" || num2=="0") return "0";
        for(int i=2; i<10; ++i) v.push_back(helper(v.back(),num1));
        for(int i=(int)num2.length()-1; i>=0; --i){
            num = v[num2[i]-'0']+oper;
            if(sol.empty()) sol=v[num2[i]-'0']+oper;
            else sol=helper(sol, num);
            oper.push_back('0');
        }
        return sol;
    }
};