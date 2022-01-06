class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dp(10001,0);
        for(vector<int> &t : trips){
            dp[t[1]]+=t[0];
            dp[t[2]]-=t[0];
        }
        for(int i=0,sz=0; i<dp.size(); ++i){
            sz+=dp[i];
            if(sz>capacity) return false;
        }
        return true;
    }
};


/*
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> &a, vector<int> &b){
            if(a[1]!=b[1]) return a[1]<b[1];
            else if(a[2]!=b[2]) return a[2]<b[2];
            return a[0]<b[0];
        });
        priority_queue<pair<int,int>> pq; //우선 순위 큐가 필요하겠네
        for(int i=0,sz=capacity; i<trips.size(); ++i){
            // 1. 시작 점이 끝거나 같으면 다 빼기
            while(!pq.empty() && trips[pq.top().second][2]<=trips[i][1]){sz+=trips[pq.top().second][0]; pq.pop();}
            // 2. 시작점 같으면 모두 다 넣기 (넣지 못하면 취소 리턴)
            for(int j=i; j<trips.size(); ++j){
                if(trips[j][1]!=trips[i][1]) break;
                else if(trips[j][0]>sz) return false;
                sz-=trips[j][0]; i=j;
                pq.push({-trips[j][2],j});
            }
        }
        return true;
    }
};
*/