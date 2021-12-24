class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visit(numCourses, 0),sol;
        vector<vector<int>> graph(numCourses);
        queue<int> q;
        int cur=0;
        for(vector<int> &v : prerequisites){
            graph[v[1]].push_back(v[0]);
            ++visit[v[0]];
        }
        for(int i=0; i<visit.size(); ++i) if(visit[i]==0) q.push(i);
        while(!q.empty()){
            cur=q.front(); q.pop();
            for(int &next : graph[cur]) if(--visit[next]==0) q.push(next);
            sol.push_back(cur);
        }
        if(sol.size() < numCourses) sol.clear();
        return sol;
    }
};