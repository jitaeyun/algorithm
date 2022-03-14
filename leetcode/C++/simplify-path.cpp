class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string t, sol;
        path.push_back('/');
        for(char &ch : path){
            if(ch=='/') {
                if(t=="..") {if(!v.empty()) {v.pop_back();} t.clear();}
                else if(t==".") t.clear();
                if(t.length()) v.push_back(t);
                t.clear();
            }
            else t.push_back(ch);
        }
        for(string &c : v) sol += "/" + c;
        return (sol.length())? sol : "/";
    }
};