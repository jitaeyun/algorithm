struct INFO{
    int recharge;
    int idx;
    int fuel;
    int location;
    bool operator()(INFO &a, INFO &b){
        if(a.recharge == b.recharge) return a.location+a.fuel < b.location+b.fuel;
        return a.recharge>b.recharge;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        INFO info = {0,-1,startFuel,0};
        vector<int> visit(stations.size(),0);
        priority_queue<INFO,vector<INFO>,INFO> pq;
        pq.push({0,-1,startFuel,0});
        while(!pq.empty()){
            info = pq.top(); pq.pop();
            if(info.idx>=0 && visit[info.idx]>info.location+info.fuel) continue;
            if(info.location+info.fuel >= target) return info.recharge;
            for(int i=info.idx+1; i<stations.size(); ++i){
                if(info.location+info.fuel >= stations[i][0]){
                    if(visit[i]<info.fuel+info.location+stations[i][1]) {
                        visit[i]=info.fuel+info.location+stations[i][1];
                        pq.push({info.recharge+1,i,info.fuel-stations[i][0]+info.location+stations[i][1],stations[i][0]});
                    }
                   
                }
                else break;
            }
        }
        return -1;
    }
};