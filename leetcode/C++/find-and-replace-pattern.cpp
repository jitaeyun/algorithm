class Solution {
public:
    string transPattern(string &p){
        string s;
        unordered_map<char,char> um;
        for(int i=0,j=0; i<p.length(); ++i){
            if(um.find(p[i])==um.end()) um[p[i]]=(char)('a'+(++j));
            s.push_back(um[p[i]]);
        }
        return s;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> sol;
        pattern=transPattern(pattern);
        for(string &s : words){
            if(pattern==transPattern(s)) sol.push_back(s); 
        }
        return sol;
    }
};