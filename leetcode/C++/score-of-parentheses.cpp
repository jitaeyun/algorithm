class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> st = {0};
        for(int i=0,val=0; i<s.length(); ++i){
            if(s[i]=='(') st.push_back(0);
            else{
                val=st.back(); st.pop_back();
                st.back() += (val>0)? 2*val : 1;
            }
        }
        return st.back();
    }
};