class Solution {
public:
    bool bfs(int &v, vector<vector<int>>& graph, vector<int> &color, vector<int> &visit){
        if(visit[v]) return true;
        queue<int> q;
        int cur=0, val=0, nval=0;
        q.push(v); visit[v]=1; color[v]=1;
        while(!q.empty()){
            cur=q.front(); val=color[cur]; nval=(val==1)? 2 : 1; q.pop();
            for(int &ncur : graph[cur]){
                if(color[ncur]>0 && color[ncur]!=nval) return false;
                else if(visit[ncur]) continue;
                q.push(ncur); visit[ncur]=1; color[ncur]=nval;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int> color(sz,0), visit(sz,0);
        for(int i=0; i<sz; ++i){
            if(!bfs(i, graph, color, visit)) return false;
        }
        return true;
    }
};