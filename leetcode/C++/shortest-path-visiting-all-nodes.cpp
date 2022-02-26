// 1. bfs solution
class INFO {
public:
    int idx, val, mask;
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int sol=0, mx=1<<(int)graph.size(), n_mask=0;
        INFO info = {0,0,0};
        vector<vector<int>> visit(graph.size(), vector<int>(mx, 0));
        queue<INFO> q;
        for(int i=0; i<graph.size(); ++i) q.push({i, 0, 1<<i});
        while(!q.empty()){
            info = q.front(); q.pop();
            if(info.mask +1 == mx) {sol = info.val; break;}
            for(int &n_idx : graph[info.idx]){
                n_mask = info.mask | (1<<n_idx);
                if(visit[n_idx][n_mask]++==0) q.push({n_idx, info.val+1, n_mask});
            }
        }
        return sol;
    }
};

// 2. floyedwarshall + dp solution
/*
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        vector<vector<int>> dist(graph.size(),vector<int>(graph.size(),-1));
        vector<vector<int>> dp(graph.size(), vector<int>((1<<(int)graph.size()),100000000));
        int mx = (1<<(int)graph.size())-1, sol = 10000000;
        for(int i=0; i<graph.size(); ++i) for(int &j : graph[i]) dist[i][j]=dist[j][i]=1;
        for(int k=0; k<graph.size(); ++k){
            for(int i=0; i<graph.size(); ++i){
                for(int j=0; j<graph.size(); ++j){
                    if(i==j || j==k || k==i || dist[i][k]==-1 || dist[k][j]==-1) continue;
                    if(dist[i][j]==-1 ||dist[i][j]>dist[i][k]+dist[k][j]) dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        for(int i=0; i<graph.size(); ++i) dp[i][1<<i]=dp[i][0]=0;
        for(int n=0; n<=mx; ++n){
            for(int i=0,l=1; i<graph.size(); ++i,l<<=1){
                if(n&l==0) continue;
                for(int j=0,m=l; j<graph.size(); ++j,m<<=1){
                    if(i==j || n&m == 0) continue;
                    dp[i][n]=min(dp[i][n], dp[j][n^l]+dist[j][i]);
                }
            }
        }
        for(int i=0; i<graph.size(); ++i) sol=min(sol, dp[i][mx]);
        return sol;
    }
};
*/