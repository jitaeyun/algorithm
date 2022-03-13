class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> um={{'(',')'},{'[',']'},{'{','}'}};
        for(char &t : s){
            if(t=='('||t=='{'||t=='[') st.push(t);
            else if(!st.empty() && um[st.top()]==t) st.pop();
            else return false;
        }
        return st.empty();
    }
};

/*
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> um = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        unordered_map<char,char>::iterator it;
        vector<char> st;
        for(char &ch : s){
            if((it=um.find(ch))!=um.end()) st.push_back(it->second);
            else if(!st.empty() && st.back()==ch) st.pop_back();
            else return false;
        }
        return st.empty();
    }
};
*/