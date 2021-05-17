class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        string sol="";
        stack<char> st;
        int visit[26],flag[26],t;
        for(int i=0; i<26; ++i) flag[i]=visit[i]=0;
        for(int i=0; i<s.length(); ++i) ++visit[s[i]-'a'];
        for(char &c : s){
            t=c-'a';
            --visit[t];
            if(flag[t]) continue;
            while(!st.empty()&&st.top()>c&&visit[st.top()-'a']) {
                flag[st.top()-'a']=0;
                st.pop();
            }
            flag[t]=1;
            st.push(c);
        }
        for(; !st.empty(); st.pop()) sol.push_back(st.top());
        reverse(sol.begin(),sol.end());
        return sol;
    }
};