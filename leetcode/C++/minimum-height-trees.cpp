class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> sol, connect(n);
        vector<vector<int>> graph(n);
        queue<int> q;
        int sz,t;
        if(edges.empty()) return {0};
        for(vector<int> &v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
            ++connect[v[0]];
            ++connect[v[1]];
        }
        for(int i=0; i<n; ++i){
            if(connect[i]==1) q.push(i);
        }
        while(!q.empty()){
            sz=q.size(); sol.clear();
            for(int i=0; i<sz; ++i){
                t=q.front(); q.pop(); sol.push_back(t);
                connect[t]=0;
                for(int &k : graph[t]){
                    if(--connect[k]==1) q.push(k);
                }
            }
        }
        return sol;
    }
};