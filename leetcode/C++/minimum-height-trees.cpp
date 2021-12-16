// 1. topology sort
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

// 2. in-out dp
/*
class Solution {
public:
    void in(int c, vector<int> &p, vector<vector<int>> &graph, vector<int> &dp){
        for(int &n : graph[c]){
            if(n==p[c]) continue;
            p[n]=c;
            in(n, p, graph, dp);
            dp[c]=max(dp[c], dp[n]+1);
        }
    }
    void out(int c, vector<int> &p, vector<vector<int>> &graph, vector<int> &dp, vector<int> &dp2){
        int mx=0, mx2=(p[c]==-1)? 0 : dp2[p[c]]+1; 
        if(p[c]>=0){
            for(int &n : graph[p[c]]){
                if(n==c || n==p[p[c]]) continue;
                mx=max(mx,dp[n]+2);
            }
        }
        dp2[c]=max(mx, mx2);
        for(int &n : graph[c]){
            if(n==p[c]) continue;
            out(n,p,graph,dp,dp2);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int mn=200000;
        vector<int> dp(n,0), dp2(n,-1), parent(n,-1), sol;
        vector<vector<int>> graph(n);
        for(vector<int> &v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        in(0,parent,graph,dp);
        out(0,parent,graph,dp,dp2);
        for(int i=0; i<n; ++i) mn=min(mn, max(dp[i],dp2[i]));
        for(int i=0; i<n; ++i) if(mn==max(dp[i],dp2[i])) sol.push_back(i);
        return sol;
    }
};
*/

// 3. find diameter
/*
class Solution {
public:
    void traverse(vector<vector<int>> &graph, vector<int> &visit, vector<int> &t_list, vector<int> &sol_list){
        visit[t_list.back()]=1;
        int f=0;
        for(int &v : graph[t_list.back()]){
            if(visit[v]) continue;
            f=1;
            t_list.push_back(v);
            traverse(graph, visit, t_list, sol_list);
            t_list.pop_back();
        }
        if(f==0 && t_list.size() > sol_list.size()) sol_list=t_list;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> visit(n,0);
        vector<int> t_list, sol_list, sol;
        int st=0,t=0;
        for(vector<int> &v : edges){
            graph[v[1]].push_back(v[0]);
            graph[v[0]].push_back(v[1]);
        }
        queue<int> q;
        q.push(0);
        visit[0]=1;
        while(!q.empty()){
            st=q.front(); q.pop();
            for(int &n : graph[st]){
                if(visit[n]) continue;
                visit[n]=1;
                q.push(n);
            }
        }
        for(int &n : visit) n=0;
        t_list.push_back(st);
        traverse(graph, visit, t_list, sol_list);
        sol.push_back(sol_list[sol_list.size()/2]);
        if(sol_list.size()>0 && sol_list.size()%2==0)  sol.push_back(sol_list[(sol_list.size()/2)-1]);
        return sol;
    }
};
*/

