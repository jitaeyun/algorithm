class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=0,t=0;
        string s="0000";
        char ch;
        unordered_set<string> us;
        for(string & t: deadends) us.insert(t);
        queue<pair<string,int>> q;
        q.push({"0000",0});
        if(us.find("0000")!=us.end()) return -1;
        else us.insert(s);
        if(s==target) return 0;
        while(!q.empty()){
            s=q.front().first; n=q.front().second; q.pop();
            for(int i=0; i<4; ++i){
                ch=s[i];
                t=s[i]-'0';
                s[i]=(t+1)%10+'0';
                if(us.find(s)==us.end()){
                    us.insert(s);
                    q.push({s,n+1});
                    if(s==target) return n+1;
                }
                s[i]=(t+9)%10+'0';
                if(us.find(s)==us.end()){
                    us.insert(s);
                    q.push({s,n+1});
                    if(s==target) return n+1;
                }
                s[i]=ch;
            }
        }
        return -1;
    }
};