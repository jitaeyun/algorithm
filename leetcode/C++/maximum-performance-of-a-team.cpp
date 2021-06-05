class Solution {
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long s=0, sol=0;
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; ++i) v.push_back({efficiency[i],speed[i]});
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        for(const pair<int,int> &p : v){
            pq.emplace(p.second);
            s+=p.second;
            if(pq.size()>k) {s-=pq.top(); pq.pop();}
            sol=max(sol, s*p.first);
        }
        return sol%mod;
    }
};