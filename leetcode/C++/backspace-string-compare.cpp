class Solution {
public:
    string transString(string &s){
        string st;
        for(char &ch : s){
            if(ch=='#' && !st.empty()) st.pop_back();
            else if(ch != '#') st.push_back(ch);
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {
        return transString(s) == transString(t);
    }
};