class Solution {
public:
    vector<int> visit;
    bool traverse(vector<int>& v, int &l, int idx, int c, int sz){
        if(sz==4) return true;
        for(int i=idx; i<visit.size(); ++i){
            if(visit[i] || c+v[i]>l) continue;
            visit[i]=1;
            if(c+v[i]<l) {if(traverse(v,l,i+1,c+v[i],sz)) return true;}
            else if(traverse(v,l,0,0,sz+1)) return true;
            visit[i]=0;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int l = 0;
        visit = vector<int>(matchsticks.size(),0);
        for(int &t : matchsticks) l+=t;
        if(l%4) return false;
        l/=4;
        return traverse(matchsticks,l,0,0,0);
    }
};