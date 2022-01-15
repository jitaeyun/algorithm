class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int idx=0, cur=0;
        while(!q.empty()){
            idx=q.front(); q.pop();
            for(int i=max(idx+minJump,cur+1); i<s.length() && i<=idx+maxJump; cur=i++){
                if(s[i]=='0'){
                    q.push(i);
                    if(i+1==s.length()) return true;
                }
            }
        }
        return false;
    }
};