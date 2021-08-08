class POINT {
public:
    int y,x,v;
};

class Solution {
public:
    int m,n;
    vector<POINT> v;
    vector<vector<POINT>> groups;
    vector<int> g;
    int find(int a){
        if(g[a]==a) return a;
        return g[a]=find(g[a]);
    }
    void unionG(int a, int b){
        a=find(a); b=find(b);
        if(a<b) g[b]=a;
        else if(a>b) g[a]=b;
    }
    void sortMatrix(vector<vector<int>>& matrix){
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                v.push_back({i,j,matrix[i][j]});
            }
        }
        sort(v.begin(),v.end(),[](POINT &a, POINT &b){return a.v<b.v;});
    }
    void makeGroup(vector<POINT> &points){
        vector<vector<POINT>> group(points.size());
        unordered_map<int,int> um;
        int a, g_key=0;
        for(int i=0; i<m+n; ++i) g[i]=i;
        for(const POINT &p : points) unionG(p.y,p.x+m);
        for(const POINT &p : points){
            a=find(p.y);
            if(um.find(a)==um.end()) um[a]=g_key++;
            group[um[a]].push_back(p);
        }
        for(const vector<POINT> &pv : group) if(!pv.empty()) groups.push_back(pv);  
    }
    void rankGroups(vector<vector<int>>& matrix){
        vector<int> row_rank(m,0), col_rank(n,0);
        for(int i=0,r; i<groups.size(); ++i){
            r=0;
            for(const POINT &p : groups[i]){
                r=max(r,row_rank[p.y]+1);
                r=max(r,col_rank[p.x]+1);
            }
            for(const POINT &p : groups[i]) matrix[p.y][p.x]=row_rank[p.y]=col_rank[p.x]=r;
        }
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        m = matrix.size(); n = matrix[0].size();
        g = vector<int>(m+n,0);
        //1. sort
        sortMatrix(matrix);
        //2. make group
        vector<POINT> points;
        for(POINT & p : v){
            if(!points.empty() && points.back().v != p.v) {
                makeGroup(points);
                points.clear();
            }
            points.push_back(p);
        }
        if(!points.empty()) {makeGroup(points); points.clear();}
        //3. calculate rank
        rankGroups(matrix);
        return matrix;
    }
};