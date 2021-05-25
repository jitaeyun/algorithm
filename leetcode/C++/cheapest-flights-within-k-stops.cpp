struct POINT{
    int c,w,n;
    bool operator()(POINT &a, POINT &b){
        if(a.c==b.c) return (a.w==b.w)? a.n>b.n : a.w>b.w;
        return a.c>b.c;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> map(n), weight(n);
        vector<int> dp(n,-1);
        priority_queue<POINT, vector<POINT>, POINT> pq;
        POINT p = {0,0,0};
        int sol=-1;
        for(vector<int> &t : flights){
            map[t[0]].push_back(t[1]);
            weight[t[0]].push_back(t[2]);
        }
        pq.push({0,0,src});
        while(!pq.empty()){
            p=pq.top(); pq.pop();
            if(p.c>k+1) break;
            else if(dp[p.n]>=0 && dp[p.n]<p.w) continue;
            else if(p.n==dst) sol=p.w;
            dp[p.n]=p.w;
            for(int i=0; i<map[p.n].size(); ++i){
                pq.push({p.c+1, p.w+weight[p.n][i], map[p.n][i]});
            }
        }
        return sol;
    }
};