class Solution {
public:
    string decodeString(string s) {
        vector<int> ns = {1};
        vector<string> ss = {""};
        for(int i=0,n=0; i<s.length(); ++i){
            if(s[i]>='0' && s[i]<='9') n=10*n+s[i]-'0';
            else if(s[i]>='a' && s[i]<='z') ss.back().push_back(s[i]);
            else if(s[i]=='['){
                (n==0)? ns.push_back(1) : ns.push_back(n);
                ss.push_back("");
                n=0;
            }
            else{
                string ts="";
                for(int i=0; i<ns.back(); ++i) ts+=ss.back();
                ss.pop_back(); ns.pop_back();
                ss.back() += ts;
            }
        }
        return ss.back();
    }
};