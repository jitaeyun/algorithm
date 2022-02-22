class Solution {
public:
    string removeKdigits(string num, int k) {
        string sol;
        int s = 0;
        for(char &ch : num){
            while(sol.length()>0 && k>0 && ch<sol.back()) {--k; sol.pop_back();}
            sol.push_back(ch);
        }
        for(; k>0; --k) sol.pop_back();
        for(; s<sol.length(); ++s) if(sol[s]!='0') break;
        return (s<sol.length())? sol.substr(s) : "0";
    }
};