class Solution {
public:
    int getIdx(char &c){
        if(c>='a'&&c<='z') return c-'a';
        return c-'A'+'z'-'a'+1;
    }
    string minWindow(string s, string t) {
        int st=0, end=-1, n=0, idx=0;
        vector<int> need(52,-1), cur(52,0);
        queue<int> q;
        for(char &ch : t){
            idx=getIdx(ch);
            if(need[idx]==-1) need[idx]=0;
            ++need[idx];
        }
        for(int i=0; i<s.length(); ++i){
            idx=getIdx(s[i]);
            if(need[idx]==-1) continue;
            q.push(i);
            if(++cur[idx]<=need[idx]) ++n; 
            while(!q.empty()) {
                idx=getIdx(s[q.front()]);
                if(cur[idx]>need[idx]) {--cur[idx]; q.pop();}
                else break;
            }
            if(n==t.length() && (end==-1 || i-q.front()<end-st)){st=q.front(); end=i;}
        }
        return (end>=0)? s.substr(st,end-st+1): "";
    }
};