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