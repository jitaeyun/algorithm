class Solution {
public:
    int distance(vector<int> &a, vector<int> &b){
        int dx=(a[0]>b[0])? a[0]-b[0] : b[0]-a[0];
        int dy=(a[1]>b[1])? a[1]-b[1] : b[1]-a[1];
        return dx+dy;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), visited=0, dist=0, cur=0, next=0, sol = 0;
        vector<vector<pair<int,int>>> graph(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visit(n,0);
        for(int i = 0, d=0; i < n; i++){
            for(int j = i+1; j < n; j++){
                d = distance(points[i], points[j]);
                graph[i].push_back({d, j});
                graph[j].push_back({d, i});
            }
        }
        visit[0]=visited=1;
        for(pair<int,int> &p : graph[0]) pq.push(p);
        while(!pq.empty() && visited < n){
            dist=pq.top().first; cur=pq.top().second; pq.pop();
            if(visit[cur]) continue;
            sol += dist; ++visited; visit[cur]=1;
            for(pair<int,int> &p : graph[cur]){
                if(visit[p.second]) continue;
                pq.push(p);
            }
        }
        return sol;
    }
};




/*
class Solution {
public:
    vector<int> group;
    int find(int &p){
        if(group[p]==-1) return p;
        return group[p]=find(group[p]);
    }
    int unions(int &a, int &b){
        int c=find(a);
        int d=find(b);
        if(c==d) return 0;
        group[c]=d;
        return 1;
    }
    int distance(vector<int> &a, vector<int> &b){
        int dx=(a[0]>b[0])? a[0]-b[0] : b[0]-a[0];
        int dy=(a[1]>b[1])? a[1]-b[1] : b[1]-a[1];
        return dx+dy;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> dp;
        int sol = 0;
        for(int i=0; i<points.size(); ++i){
            group.push_back(-1);
            for(int j=i+1; j<points.size(); ++j){
                dp.push_back({distance(points[i],points[j]),i,j});
            }
        }
        sort(dp.begin(),dp.end());
        for(int i=0,idx=0; i<dp.size()&&idx<points.size(); ++i){
            if(unions(dp[i][1],dp[i][2])) {
                ++idx; sol+=dp[i][0];
            }
        }
        return sol;
    }
};
*/