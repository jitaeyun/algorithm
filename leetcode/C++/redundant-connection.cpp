class Solution {
public:
    vector<int> visit;
    int unions(int &a, int &b){
        int va=find(a), vb=find(b);
        if(va!=vb) visit[vb]=va;
        return va!=vb;
    }
    int find(int n){
        if(visit[n]==0) return n;
        return visit[n]=find(visit[n]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int idx=0;
        visit=vector<int>(edges.size()+1,0);
        for(int i=0; i<edges.size(); ++i){
            if(unions(edges[i][0],edges[i][1])==0) idx=i;
        }
        return edges[idx];
    }
};