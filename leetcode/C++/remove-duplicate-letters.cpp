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


/*
//using stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string sol;
        vector<int> visit(26,0), v(26,0);
        int idx;
        for(char &ch : s) ++v[ch-'a'];
        for(char &ch : s){
            idx = ch-'a';
            --v[idx];
            if(visit[idx]) continue;
            for(; sol.length()>0 && sol.back() > ch && v[sol.back()-'a']>0; sol.pop_back()) visit[sol.back()-'a']=0;
            sol.push_back(ch);
            visit[idx]=1;
        }
        return sol;
    }
};
*/



/*
// using bitmask
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string sol;
        int visit=0;
        vector<int> v(s.length(),0);
        for(int i=(int)s.length()-1; i>=0; --i) {
            visit|=(1<<(s[i]-'a'));
            v[i]=visit;
        }
        for(int i=0, idx=0,max_idx=-1; i<26 && visit>0; ++i){
            max_idx=-1;
            for(int j=idx; j<s.length() && (v[j]&visit)==visit; ++j){
                if(((1<<(s[j]-'a'))&visit)==0) continue;
                else if(max_idx==-1) max_idx=j;
                else if(s[max_idx]>s[j]) max_idx=j;
            }
            sol.push_back(s[max_idx]);
            visit^=(1<<(s[max_idx]-'a'));
            idx=max_idx+1;
        }
        return sol;
    }
};
*/