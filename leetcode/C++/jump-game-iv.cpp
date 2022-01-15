class Solution {
public:
    int minJumps(vector<int>& arr) {
        int cur_idx=0, next_idx=0, d[] = {-1,1};
        vector<int> visit(arr.size(),-1);
        queue<int> q;
        unordered_map<int,vector<int>> um;
        for(int i=0; i<arr.size(); ++i) um[arr[i]].push_back(i);
        q.push(0);
        visit[0] = 0;
        while(!q.empty()){
            cur_idx = q.front(); q.pop();
            if(cur_idx + 1 == arr.size()) return visit[cur_idx];
            for(int i=0; i<2; ++i){
                next_idx = cur_idx + d[i];
                if(next_idx < 0 || next_idx >= arr.size() || visit[next_idx] > -1) continue;
                q.push(next_idx); visit[next_idx] = visit[cur_idx] + 1;
            }
            vector<int> &v = um[arr[cur_idx]];
            for(int i=(int)v.size()-1; i>=0; --i){
                next_idx = v[i];
                if(visit[next_idx] == -1) { q.push(next_idx); visit[next_idx] = visit[cur_idx] + 1;}
                v.pop_back();
            }
        }
        return visit.back();
    }
};