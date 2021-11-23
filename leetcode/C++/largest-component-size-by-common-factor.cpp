class Solution {
public:
    vector<int> group;
    int find(int g){
        if(group[g]==0) return g;
        return group[g]=find(group[g]);
    }
    int unions(int a, int b){
        a=find(a); b=find(b);
        if(a<b) group[b]=a;
        else if(a>b) group[a]=b;
        return min(a,b);
    }
    int largestComponentSize(vector<int>& nums) {
        int sol=0, g=0;
        vector<int> v(100001,-1), aggr(1,0);
        vector<int> is_prime(100001,1); is_prime[0]=is_prime[1]=0;
        group.push_back(0);
        for(int &n : nums) v[n]=0;
        for(int i=2; i<100001; ++i){
            if(is_prime[i]==0) continue;
            g = (int)group.size();
            group.push_back(0); aggr.push_back(0);
            for(int j=i; j<100001; j+=i) {
                if(i<j) is_prime[j]=0;
                if(v[j]==0) v[j]=g;
                else if(v[j]>0) v[j]=unions(v[j],g);
            }
        }
        for(int &n : nums){
            g=find(v[n]); ++aggr[g];
            sol=max(sol,aggr[g]);
        }
        return sol;
    }
};