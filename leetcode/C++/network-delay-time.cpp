class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> p(n+1), w(n+1);
        vector<int> visit(n+1,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sol=0, node, val, next_node, next_val;
        for(int i=0; i<times.size(); ++i){
            p[times[i][0]].push_back(times[i][1]);
            w[times[i][0]].push_back(times[i][2]);
        } 
        pq.push({0,k});
        while(!pq.empty() && n){
            node=pq.top().second; val=pq.top().first; pq.pop();
            if(visit[node]) continue;
            visit[node]=1; --n;
            if(sol<val) sol=val;
            for(int i=0; i<p[node].size()&&n; ++i){
                if(visit[p[node][i]]) continue;
                next_node=p[node][i]; next_val=val+w[node][i];
                pq.push({next_val,next_node});
            }
        }
        return (n==0)? sol : -1;
    }
};