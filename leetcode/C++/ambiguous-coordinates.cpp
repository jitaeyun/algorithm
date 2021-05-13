class Solution {
public:
    vector<string> sol;
    void makeSubCoordinate(string &s, vector<string> &v){
        if(s.length()==1) v.push_back(s);
        else if(s[0]=='0'&&s.back()=='0') return;
        else if(s[0]=='0') v.push_back(s.substr(0,1)+"."+s.substr(1));
        else if(s.back()=='0') v.push_back(s);
        else {
            v.push_back(s);
            for(int i=1; i<s.length(); ++i) 
                v.push_back(s.substr(0,i)+"."+s.substr(i));
        }
    }
    void makeCoordinate(string &s, int del){
        vector<string> v[2];
        string str[2]={s.substr(0,del), s.substr(del)};
        for(int i=0; i<2; ++i) makeSubCoordinate(str[i],v[i]);
        for(int i=0; i<v[0].size(); ++i)
            for(int j=0; j<v[1].size(); ++j)
                sol.push_back("("+v[0][i]+", "+v[1][j]+")");
    }
    vector<string> ambiguousCoordinates(string s) {
        string t=s.substr(1,s.length()-2);
        for(int i=1; i<t.length(); ++i) makeCoordinate(t,i);
        return sol;
    }
};