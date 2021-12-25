class Solution {
public:
    int calculate(string s) {
        int sol=0,op=0; //1 2 3 4 + - * /
        vector<int> nums;
        for(int i=0,j=0,t=0; i<s.length(); j=++i){
            if(s[i]==' ') continue;
            else if(s[i]=='+') op=1;
            else if(s[i]=='-') op=2;
            else if(s[i]=='*') op=3;
            else if(s[i]=='/') op=4;
            else {
                while(i<s.length() && s[i]>='0' && s[i]<='9') ++i;
                t = stoi(s.substr(j,(i--)-j));
                if(op==0 || op==1) nums.push_back(t);
                else if(op==2) nums.push_back(-t);
                else if(op==3) nums.back()*=t;
                else nums.back()/=t;
            }
        }
        for(int &n : nums) sol+=n;
        return sol;
    }
};