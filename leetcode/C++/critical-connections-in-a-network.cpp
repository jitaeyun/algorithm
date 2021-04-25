int visited[100000],r[100000];
class Solution {
public:
    vector<int> v[100000];
    vector<vector<int>> sol;
    void dfs(int prev,int cur,int t){
        visited[cur]=1;
        r[cur]=t;
        for(int i=0,next; i<v[cur].size(); ++i){
            next=v[cur][i];
            if(next==prev) continue;
            else if(visited[next]==0) dfs(cur,next,t+1);
            r[cur] = min(r[cur],r[next]);
            if(r[next]>t) sol.push_back({cur,next});
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        for(int i=0; i<c.size(); ++i){
            visited[c[i][0]]=visited[c[i][1]]=0;
            v[c[i][0]].push_back(c[i][1]);
            v[c[i][1]].push_back(c[i][0]);
        }
        dfs(-1,0,0);
        return sol;
    }
};