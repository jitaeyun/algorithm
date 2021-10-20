class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string t = "";
        string sol;
        for(char &ch : s){
            if(ch==' ' && t.length()==0) continue;
            else if(ch==' ' && t.length()>0){
                v.push_back(t);
                t="";
            }
            else t.push_back(ch);
        }
        if(t.length()>0) v.push_back(t);
        for(int i=(int)v.size()-1; i>=0; --i) sol+=v[i]+' ';
        if(sol.length()>0) sol.pop_back();
        return sol;
    }
};