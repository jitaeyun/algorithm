class Solution {
public:
    string pushDominoes(string dominoes) {
        int idx, next;
        vector<int> visit(dominoes.length(),0), v(dominoes.length(),0);
        queue<int> q;
        for(int i=0; i<dominoes.length(); ++i){
            if(dominoes[i]=='L') {
                visit[i]=1; v[i]=-1; q.push(i); 
            }
            else if(dominoes[i]=='R') {
                v[i]=visit[i]=1; q.push(i); 
            }
        }
        while(!q.empty()){
            idx=q.front(); q.pop();
            next=idx+v[idx];
            if(v[idx]==0) continue;
            if(next<0 || next>=dominoes.length()) continue;
            if(visit[next]&&visit[idx]+1>visit[next]) continue;
            visit[next]=visit[idx]+1;
            v[next]+=v[idx];
            q.push(next);
        }
        for(int i=0; i<dominoes.length(); ++i){
            if(v[i]==-1) dominoes[i]='L';
            else if(v[i]==1) dominoes[i]='R';
            else dominoes[i]='.';
        }
        return dominoes;
    }
};