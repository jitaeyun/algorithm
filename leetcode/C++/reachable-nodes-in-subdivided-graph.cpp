class POINT {
public:
    int v,d;
    bool operator()(POINT &a, POINT &b){
        return a.d>b.d;
    }
};
class Solution {
public:
    const int MAX_VAL = 1000000000;
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        int sol=0,v=0,d=0;
        vector<int> visit(n,MAX_VAL);
        vector<vector<int>> remain(n,vector<int>(n,0));
        vector<vector<pair<int,int>>> graph(n);
        priority_queue<POINT,vector<POINT>,POINT> pq;
        // 1. make graph
        for(vector<int> &e : edges){
            graph[e[0]].push_back({e[1],e[2]});
            graph[e[1]].push_back({e[0],e[2]});
        }
        // 2. traverse
        pq.push({0,0});
        while(!pq.empty()){
            v=pq.top().v; d=pq.top().d; pq.pop();
            if(visit[v]<=d) continue;
            visit[v]=d;
            for(const pair<int,int> &p : graph[v]){
                // 2.1 remain 점 갱신
                remain[v][p.first]=max(remain[v][p.first],min(p.second,maxMoves-d));
                // 2.2 다음점 이동 가능하면 최소거리인지 확인하고 가능하면 넣음
                if(d+p.second+1<=maxMoves && d+p.second+1<visit[p.first]){
                    pq.push({p.first,d+p.second+1});
                }
            }
            
        }
        // 3. calculation
        // 3.1 다른점 이동가능한 경우 계산 
        for(int i=0; i<n; ++i) if(visit[i]<MAX_VAL) ++sol;
        // 3.2 점과 점사이의 이동가능한 카운트 갯수 계산
        for(vector<int> &e : edges) sol+=min(e[2],remain[e[0]][e[1]]+remain[e[1]][e[0]]);
        return sol;
    }
};